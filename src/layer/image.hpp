#pragma once

#include "fbo_canvas.hpp"
#include "libs/image_preloader.hpp"
#include "../gui/view/media_selector.hpp"

namespace atlas {
    namespace layer {
        class Image : public FboCanvas {
        public:
            void setup(const int layerIndex,const atlas::core::AppSettings &settings);
            void update(const double delta);
            void gui();
            int getLayerType() {
                return LAYER_TYPE_IMAGE;
            }
            
        protected:
            atlas::gui::view::MediaSelector mediaSelector;
            atlas::layer::libs::ImagePreloader preloader;
            
            ofImage image;
        };
    }
}
