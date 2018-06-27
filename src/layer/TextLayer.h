#pragma once

#include "FboLayer.h"

class TextLayer : public FboLayer {
public:
    TextLayer(int width, int height);
    ~TextLayer();
    
    void update();
    std::string getName() {
        return "Text";
    }
    
protected:
    char text[1024];
    int size;
    float lineHeight, letterSpacing;
    
    char fontName[256];
    int timeDisplay, timeHidden, timeAnimation;
    
    ofTrueTypeFont font;
    
    void displayGui();
    void customGui();
};
