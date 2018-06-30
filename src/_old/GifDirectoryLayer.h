#pragma once

#include "FboLayer.h"
#include "utils/GifPreloader.h"
#include "gif/GifDecoder.h"

class GifDirectoryLayer : public FboLayer {
public:
    GifDirectoryLayer(int width, int height);
    ~GifDirectoryLayer();
    
    void load();
    void loadAppend();
    void play();
    void stop();
    void update();
    std::string getName() {
        return "GifDirectory";
    }
    
protected:    
    static const int PRELOAD_QUEUE_SIZE = 3;
    
    char directory[512] = "";
    
    GifPreloader preloader;
    
    float frame;
    std::shared_ptr<GifDecoder> currentGif;
    std::queue<std::shared_ptr<GifDecoder>> preloadQueue;
    std::vector<std::string> gifList;
    int gifListIndex;
    
    bool playGif = true;
    
    void displayGui();
    void customGui();
};
