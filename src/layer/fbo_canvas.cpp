#include "fbo_canvas.hpp"

#include "../core/app.hpp"

void atlas::layer::FboCanvas::setup(const atlas::core::AppSettings &settings) {
    this->fbo = std::make_shared<ofFbo>();
    this->fbo->allocate(settings.compositorOutputWidth,
                        settings.compositorOutputWidth);
}

void atlas::layer::FboCanvas::update(double delta) {
    
}

const std::shared_ptr<ofFbo>& atlas::layer::FboCanvas::getFrame() {
    return this->fbo;
}

void atlas::layer::FboCanvas::renderGui() {
    
}
