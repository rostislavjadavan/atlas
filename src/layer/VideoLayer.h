#pragma once

#include "FboLayer.h"

class VideoLayer : public FboLayer {
public:
    VideoLayer(int width, int height);
    ~VideoLayer();
    
    void load();
    void play();
    void stop();
    void update();

protected:
    ofVideoPlayer video;
    char filename[256] = "";
    
    void displayGui();
    void customGui();
};
