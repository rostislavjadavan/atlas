#pragma once

#include "../core/AbstractLayer.h"

class FboLayer: public AbstractLayer {
    public:
    	FboLayer(int width, int height);
    	~FboLayer();
        void setup();
        void displayGui();
        void update();
        ofFbo getOutput();

    private:
        int width, height;
        ofFbo fbo;
};
