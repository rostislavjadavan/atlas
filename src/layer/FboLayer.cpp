#include "FboLayer.h"

FboLayer::FboLayer(int width, int height) {
	this->width = width;
    this->height = height;
    fbo.allocate(width, height, GL_RGBA);
}
FboLayer::~FboLayer() {}

void FboLayer::setup() {
}

void FboLayer::displayGui() {
}

void FboLayer::update() {
    fbo.begin();
    ofClear(0, 0, 0, 255);
    fbo.end();
}

ofFbo FboLayer::getOutput() {
    return this->fbo;
}
