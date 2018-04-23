#pragma once

#include "FboLayer.h"
#include "gif/GifDecoder.h"

class GifLayer : public FboLayer {
public:
    GifLayer(int width, int height);
    ~GifLayer();
    
    void load();
    void play();
    void stop();
    void update();
    
protected:
    float frame;
    
    bool isLoaded = false;
    GifDecoder gif;
    char filename[256] = "";
    
    void displayGui();
    void customGui();
};
