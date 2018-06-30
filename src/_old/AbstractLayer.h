#pragma once

#include "LayerInfo.h"
#include "ofMain.h"

class AbstractLayer {
public:
  	AbstractLayer();
   	int getLayerId();
   	std::string getLayerIdString();

    virtual void setup() = 0;
    virtual void displayGui() = 0;
    virtual void update() = 0;
    virtual LayerInfo &getInfo() = 0;
    virtual ofFbo getOutput() = 0;
    virtual std::string getName() = 0;

private:
   	static int layerCounter;
   	int layerId;
}; 
