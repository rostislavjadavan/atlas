#pragma once

#include "FboLayer.h"
#include "utils/GifPreloader.h"
#include "gif/GifDecoder.h"

class GifLayer : public FboLayer {
public:
    GifLayer(int width, int height);
    ~GifLayer();
    
    void play();
    void stop();
    void update();
    std::string getName() {
        return "Gif";
    }
    
protected:
    float frame;
    std::shared_ptr<GifDecoder> gif;
    bool playGif = true;
    
    char filename[256] = "";
    GifPreloader preloader;
    
    void displayGui();
    void customGui();
};
