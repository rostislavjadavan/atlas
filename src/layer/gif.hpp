#pragma once

#include "fbo_canvas.hpp"
#include "../libs/gif/GifDecoder.h"
#include "../libs/gif/GifPreloader.h"
#include "../gui/view/media_selector.hpp"

namespace atlas {
    namespace layer {
        class Gif : public FboCanvas {
        public:
            void setup(const int layerIndex,const atlas::core::AppSettings &settings);
            void update(const double delta);
            void gui();
            int getLayerType() {
                return LAYER_TYPE_GIF;
            }
            
        protected:
            GifPreloader preloader;
            
            atlas::gui::view::MediaSelector mediaSelector;
            
            float frame;
            std::shared_ptr<GifDecoder> currentGif;

            bool playGif = true;
            
            atlas::core::BpmModifier bpmFrame;
        };
    }
}
