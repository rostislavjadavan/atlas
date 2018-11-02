#pragma once

#include "fbo_canvas.hpp"
#include "libs/gif_preloader.hpp"
#include "../gui/view/media_selector.hpp"

namespace atlas {
    namespace layer {
        class GifDirectory : public FboCanvas {
        public:
            void setup(const int layerIndex,const atlas::core::AppSettings &settings);
            void update(const double delta);
            void gui();
            int getLayerType() {
                return atlas::layer::LAYER_TYPE_GIFDIRECTORY;
            }
            json saveJson();
            void loadJson(const json &j);
            
        protected:
            static const int PRELOAD_QUEUE_SIZE = 128;
            atlas::layer::libs::GifPreloader preloader;
            
            atlas::gui::view::MediaSelector mediaSelector;
            
            float frame;
            std::shared_ptr<GifDecoder> currentGif;
            std::queue<std::shared_ptr<GifDecoder>> preloadQueue;
            std::vector<std::string> gifList;
            int gifListIndex;
            
            bool playGif = true;
            
            void load();
            
            atlas::core::BpmModifier bpmFrame, bpmNextGif;
            float nextGifTrigger = 0.0f;
        };
    }
}
