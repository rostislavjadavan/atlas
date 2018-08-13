#include "gif_preloader.hpp"

void atlas::layer::libs::GifPreloader::preload(std::string path) {
    this->status = LOADING;
    this->fpGifDecoder = std::async(std::launch::async, [](std::string path) {
        std::shared_ptr<GifDecoder> decoder = std::shared_ptr<GifDecoder>(new GifDecoder());
        decoder->load(ofToDataPath(path).c_str());
        return decoder;
    }, path);
}

int atlas::layer::libs::GifPreloader::getStatus() {
    if (!this->fpGifDecoder.valid() || this->status == WAITING) {
        this->status = WAITING;
    } else if (future_status::ready == this->fpGifDecoder.wait_for(std::chrono::seconds(0))) {
        this->status = PREPARED;
    } else {
        this->status = LOADING;
    }
    
    return this->status;
}

std::shared_ptr<GifDecoder> atlas::layer::libs::GifPreloader::get() {
    this->status = WAITING;
    return this->fpGifDecoder.get();
}

