#pragma once

#include "fbo_canvas.hpp"
#include "libs/gif_preloader.hpp"
#include "../gui/view/media_selector.hpp"

namespace atlas {
    namespace layer {
        class Gif : public FboCanvas {
        public:
            void setup(const int layerIndex,const atlas::core::AppSettings &settings);
            void update(const double delta);
            void gui();
            int getLayerType() {
                return atlas::layer::LAYER_TYPE_GIF;
            }
            json saveJson();
            void loadJson(const json &j);
            
        protected:
            atlas::layer::libs::GifPreloader preloader;
            
            atlas::gui::view::MediaSelector mediaSelector;
            
            float frame;
            std::shared_ptr<GifDecoder> currentGif;

            bool playGif = true;
            void load();
            
            atlas::core::BpmModifier bpmFrame;
        };
    }
}
