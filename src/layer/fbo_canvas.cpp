#include "fbo_canvas.hpp"

#include "../core/app.hpp"

void atlas::layer::FboCanvas::setup(const int layerIndex, const atlas::core::AppSettings &settings) {
    this->fbo = std::make_shared<ofFbo>();
    this->fbo->allocate(settings.compositorOutputWidth,
                        settings.compositorOutputHeight);
    this->layerDrawMode = FIT;
    this->layerIndex = layerIndex;
}

const std::shared_ptr<ofFbo>& atlas::layer::FboCanvas::getFrame() {
    return this->fbo;
}

void atlas::layer::FboCanvas::drawTexture(const ofTexture &tex) {
    const float width = atlas::core::App::instance().settings.compositorOutputWidth;
    const float height = atlas::core::App::instance().settings.compositorOutputHeight;
    float fx, fy, fw, fh;
    
    switch(this->layerDrawMode) {
        case LayerDrawMode::FIT: {
            float scale = std::fmin(tex.getHeight()/height, tex.getWidth()/width);
            fx = width/2 - tex.getWidth() / 2 / scale;
            fy = height/2 - tex.getHeight() / 2 / scale;
            fw = tex.getWidth() / scale;
            fh = tex.getHeight() / scale;
            break;
        }
        case LayerDrawMode::STRETCH: {
            fx = 0;
            fy = 0;
            fw = width;
            fh = height;
            break;
        }
        case LayerDrawMode::ORIGINAL:
        default:
            fx = width/2 - tex.getWidth() / 2;
            fy = height/2 - tex.getHeight() / 2;
            fw = tex.getWidth();
            fh = tex.getHeight();
    }
    tex.draw(fx, fy, fw, fh);
}
