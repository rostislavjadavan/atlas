#pragma once

#include "../core/AbstractLayer.h"

class EmptyLayer: public AbstractLayer {
    public:
        void setup(int width, int height);
        void displayGui();
        void update();
        ofFbo getOutput();

    private:
        int width, height;
        ofFbo fbo;
};
