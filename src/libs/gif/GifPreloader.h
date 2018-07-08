#pragma once

#include "ofMain.h"
#include "GifDecoder.h"
#include <string>
#include <future>

class GifPreloader {
public:
    static const int WAITING = 0;
    static const int LOADING = 1;
    static const int PREPARED = 2;
    
    void preload(std::string path);
    int getStatus();
    std::shared_ptr<GifDecoder> get();
    
protected:
    int status = 0;
    std::future<std::shared_ptr<GifDecoder>> fpGifDecoder;
};
