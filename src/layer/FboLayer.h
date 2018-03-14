#pragma once

#include "../core/AbstractLayer.h"
#include "ofMain.h"
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

    protected:
    	void commonGui();
    	void customGui();

        int width, height;
        ofFbo fbo;
        LayerInfo layerInfo;

        int guiBlendMode;
};
