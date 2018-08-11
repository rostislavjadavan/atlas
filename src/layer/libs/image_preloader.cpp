#include "image_preloader.hpp"

void atlas::layer::libs::ImagePreloader::preload(std::string path) {
    this->status = LOADING;
    this->pixels = std::async(std::launch::async, [](std::string path) {
        ofPixels pixels;
        ofLoadImage(pixels, path);
        return std::make_shared<ofPixels>(pixels);
    }, path);
}

int atlas::layer::libs::ImagePreloader::getStatus() {
    if (!this->pixels.valid() || this->status == WAITING) {
        this->status = WAITING;
    } else if (future_status::ready == this->pixels.wait_for(std::chrono::seconds(0))) {
        this->status = PREPARED;
    } else {
        this->status = LOADING;
    }
    
    return this->status;
}

std::shared_ptr<ofPixels> atlas::layer::libs::ImagePreloader::get() {
    this->status = WAITING;
    return this->pixels.get();
}
