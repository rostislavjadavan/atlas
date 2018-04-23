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
    
    float getDelta() {
        return this->delta;
    }
    
protected:
    void commonGui();
    void customGui();
    
    int width, height;
    ofFbo fbo;
    LayerInfo layerInfo;
    
    int guiBlendMode;
    
    void reinit(int width, int height);
    
    double lastElapsedTime = 0;
    float delta = 0;
    void calcDelta() {
        this->delta = ofGetElapsedTimeMillis() - this->lastElapsedTime;
        this->lastElapsedTime = ofGetElapsedTimeMillis();
    }
};
