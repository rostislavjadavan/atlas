#pragma once

#include "fbo_canvas.hpp"
#include "../libs/gif/GifDecoder.h"
#include "../libs/gif/GifPreloader.h"

namespace atlas {
    namespace layer {
        class GifDirectory : public FboCanvas {
        public:
            void setup(const int layerIndex,const atlas::core::AppSettings &settings);
            void update(const double delta);
            void gui();
            int getLayerType() {
                return LAYER_TYPE_GIFDIRECTORY;
            }
            
        protected:
            static const int PRELOAD_QUEUE_SIZE = 3;
            
            char directory[512] = "";
            
            GifPreloader preloader;
            
            float frame;
            std::shared_ptr<GifDecoder> currentGif;
            std::queue<std::shared_ptr<GifDecoder>> preloadQueue;
            std::vector<std::string> gifList;
            int gifListIndex;
            
            bool playGif = true;
            
            void load();
            void play();
            void stop();
        };
    }
}
