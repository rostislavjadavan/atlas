#include "FboLayer.h"

FboLayer::FboLayer(int width, int height) {
	this->width = width;
    this->height = height;
    fbo.allocate(width, height, GL_RGBA);

    this->layerInfo.width = width;
    this->layerInfo.height = height;
    this->layerInfo.posX = 0;
    this->layerInfo.posY = 0;
    this->layerInfo.alpha = 0.5f;
    this->layerInfo.blendMode = OF_BLENDMODE_ALPHA;
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

LayerInfo &FboLayer::getInfo() {
	return this->layerInfo;
}

ofFbo FboLayer::getOutput() {
    return this->fbo;
}
