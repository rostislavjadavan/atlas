#include "layer_compositor.hpp"

atlas::core::LayerCompositor::LayerCompositor(std::shared_ptr<LayerContainer> container, const AppSettings &settings) {
    this->container = container;
    this->fbo = std::make_shared<ofFbo>();
    this->fbo->allocate(settings.compositorOutputWidth, settings.compositorOutputHeight);
    
    this->blendShaders.setup();
    
    this->quad.getVertices().resize(4);
    this->quad.getTexCoords().resize(4);
    this->quad.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    
    this->quad.setVertex(0, ofVec3f(0, 0, 0));
    this->quad.setVertex(1, ofVec3f(settings.compositorOutputWidth, 0, 0));
    this->quad.setVertex(2, ofVec3f(settings.compositorOutputWidth, settings.compositorOutputHeight, 0));
    this->quad.setVertex(3, ofVec3f(0, settings.compositorOutputHeight, 0));
    
    this->quad.setTexCoord(0, ofVec2f(0, 0));
    this->quad.setTexCoord(1, ofVec2f(settings.compositorOutputWidth, 0));
    this->quad.setTexCoord(2, ofVec2f(settings.compositorOutputWidth, settings.compositorOutputHeight));
    this->quad.setTexCoord(3, ofVec2f(0, settings.compositorOutputHeight));
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
    if (layer->getLayerType() == atlas::layer::LAYER_TYPE_EMPTY) {
        return;
    }
    
    ofSetColor(255, 255, 255, 255);
    layer->update(this->delta);
    
    this->blendShaders.begin(this->fbo->getTexture(), layer->getFrame()->getTexture(), BlendShaders::BLEND_MODE_ADD);
    this->quad.draw();
    this->blendShaders.end();
}

const shared_ptr<ofFbo>& atlas::core::LayerCompositor::getFrame() {
    return this->fbo;
}
