#pragma once

#include "ofMain.h"

class AbstractLayer {
    public:
        virtual void setup() = 0;
        virtual void displayGui() = 0;
        virtual void update() = 0;
        virtual ofFbo getOutput() = 0;
}; 
