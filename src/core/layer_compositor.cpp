#include "layer_compositor.hpp"

atlas::core::LayerCompositor::LayerCompositor(std::shared_ptr<LayerContainer> container, const AppSettings &settings) {
    this->container = container;
    this->fbo = std::make_shared<ofFbo>();
    this->fbo->allocate(settings.compositorOutputWidth, settings.compositorOutputHeight);
}

void atlas::core::LayerCompositor::update() {
    this->delta = ofGetElapsedTimeMillis() - this->lastElapsedTime;
    this->lastElapsedTime = ofGetElapsedTimeMillis();
    
    this->fbo->begin();
    ofClear(0, 0, 0, 255);
    
    for (int i = 0; i < this->container->NUM_LAYERS; i++) {
        this->renderLayer(i);
    }
    
    this->fbo->end();
}

inline void atlas::core::LayerCompositor::renderLayer(int index) {
    const shared_ptr<atlas::layer::Base> layer = this->container->getLayer(index);
    if (layer->getFrame() == nullptr) {
        return;
    }
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetColor(255, 255, 255, 255);
    
    layer->update(this->delta);
    layer->getFrame()->draw(ofRectangle(0, 0, this->fbo->getWidth(), this->fbo->getHeight()));
    
    ofSetColor(255, 255, 255);
    ofDisableBlendMode();
}

const shared_ptr<ofFbo>& atlas::core::LayerCompositor::getFrame() {
    return this->fbo;
}
