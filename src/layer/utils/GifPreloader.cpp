#include "GifPreloader.h"

void GifPreloader::preload(std::string path) {
    this->status = LOADING;
    this->fpGifDecoder = std::async(std::launch::async, [](std::string path) {
        ofLog(OF_LOG_NOTICE) << "[GifPreloader] loading: " << path;
        
        std::shared_ptr<GifDecoder> decoder = std::shared_ptr<GifDecoder>(new GifDecoder());
        decoder->load(ofToDataPath(path).c_str());
        
        ofLog(OF_LOG_NOTICE) << "[GifPreloader] done: " << path << ", width: " << decoder->getWidth() << ", height: " << decoder->getHeight() << ", frames: " << decoder->getFrameCount();
        
        return decoder;
    }, path);
}

int GifPreloader::getStatus() {
    if (!this->fpGifDecoder.valid() || this->status == WAITING) {
        this->status = WAITING;
    } else if (future_status::ready == this->fpGifDecoder.wait_for(std::chrono::seconds(0))) {
        this->status = PREPARED;
    } else {
        this->status = LOADING;
    }
    
    return this->status;
}

std::shared_ptr<GifDecoder> GifPreloader::get() {
    this->status = WAITING;
    return this->fpGifDecoder.get();
}

