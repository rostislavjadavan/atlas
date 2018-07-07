#include "layer_compositor.hpp"

atlas::core::LayerCompositor::LayerCompositor(std::shared_ptr<LayerContainer> container, const AppSettings &settings) {
    this->container = container;
    this->fbo = std::make_shared<ofFbo>();
    this->fbo->allocate(settings.compositorOutputWidth, settings.compositorOutputHeight);
}

void atlas::core::LayerCompositor::update() {
    this->delta = ofGetElapsedTimeMillis() - this->lastElapsedTime;
    this->lastElapsedTime = ofGetElapsedTimeMillis();
    
    for (int i = 0; i < this->container->NUM_LAYERS; i++) {
        if (this->container->getLayer(i).use_count() > 0) {
            this->container->getLayer(i)->update(this->delta);
        }
    }
}

const ofFbo& atlas::core::LayerCompositor::getFrame() {
    
}
