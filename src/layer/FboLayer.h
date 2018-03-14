#pragma once

#include "../core/AbstractLayer.h"
#include "ofxImGui.h"

class FboLayer: public AbstractLayer {
    public:
    	FboLayer(int width, int height);
    	~FboLayer();
        void setup();
        void displayGui();
        void update();
        LayerInfo &getInfo();
        ofFbo getOutput();

    private:
        int width, height;
        ofFbo fbo;
        LayerInfo layerInfo;
};
