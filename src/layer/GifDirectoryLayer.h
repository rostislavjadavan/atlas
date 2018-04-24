#pragma once

#include "FboLayer.h"
#include "gif/GifDecoder.h"
#include <vector>

class GifDirectoryLayer : public FboLayer {
public:
    GifDirectoryLayer(int width, int height);
    ~GifDirectoryLayer();
    
    void load();
    void play();
    void stop();
    void update();
    
protected:
    float frame;
    int gif;
    
    bool isLoaded = false;
    ofDirectory gifs;
    char directory[512] = "";
    
    GifDecoder *currentGif, *nextGif;
    bool isNextGifLoaded = false;
    
    void displayGui();
    void customGui();
};
