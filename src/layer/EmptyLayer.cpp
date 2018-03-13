#include "EmptyLayer.h"

void EmptyLayer::setup(int width, int height) {
    this->width = width;
    this->height = height;
    fbo.allocate(width, height, GL_RGBA);
}

void EmptyLayer::displayGui() {
}

void EmptyLayer::update() {
    fbo.begin();
    ofClear(0, 0, 255, 255);
    fbo.end();
}

ofFbo EmptyLayer::getOutput() {
    return this->fbo;
}
