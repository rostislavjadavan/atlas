#pragma once

#include "../_output/AbstractLayer.h"
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
    std::string getName() {
        return "FBO";
    }
    
    float getDelta() {
        return this->delta;
    }
    
protected:
    void commonGui();
    void customGui();
    
    void updateBegin();
    void updateEnd();
    
    int width, height;
    ofFbo fbo;
    LayerInfo layerInfo;
    
    int guiBlendMode;
    int guiDrawMode;
    
    void reinit(int width, int height);
    void drawTexture(const ofTexture &tex);
    
    double lastElapsedTime = 0;
    float delta = 0;
    void calcDelta() {
        this->delta = ofGetElapsedTimeMillis() - this->lastElapsedTime;
        this->lastElapsedTime = ofGetElapsedTimeMillis();
    }
};
