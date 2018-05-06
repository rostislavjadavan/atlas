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
    
protected:
    float frame;
    std::shared_ptr<GifDecoder> gif;
    
    char filename[256] = "";
    GifPreloader preloader;
    
    void displayGui();
    void customGui();
};
