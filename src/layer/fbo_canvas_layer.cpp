#include "fbo_canvas_layer.hpp"

#include "../core/app.hpp"

void atlas::layer::FboCanvas::setup() {
    this->fbo = std::make_shared<ofFbo>();
    this->fbo->allocate(atlas::core::App::instance().settings.compositorOutputWidth,
                        atlas::core::App::instance().settings.compositorOutputHeight);
}

void atlas::layer::FboCanvas::update(double delta) {
    
}

const std::shared_ptr<ofFbo>& atlas::layer::FboCanvas::getFrame() {
    return this->fbo;
}
