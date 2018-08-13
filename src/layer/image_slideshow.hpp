#pragma once

#pragma once

#include "fbo_canvas.hpp"
#include "libs/image_preloader.hpp"
#include "../gui/view/media_selector.hpp"

namespace atlas {
    namespace layer {
        class ImageSlideshow : public FboCanvas {
        public:
            void setup(const int layerIndex,const atlas::core::AppSettings &settings);
            void update(const double delta);
            void gui();
            int getLayerType() {
                return atlas::layer::LAYER_TYPE_IMAGESLIDESHOW;
            }
            json saveJson();
            void loadJson(const json &j);
            
        protected:
            atlas::gui::view::MediaSelector mediaSelector;
            
            static const int PRELOAD_QUEUE_SIZE = 3;
            atlas::layer::libs::ImagePreloader preloader;
            
            std::shared_ptr<ofImage> currentImage;
            float currentImageTime;
            std::queue<std::shared_ptr<ofImage>> preloadQueue;
            std::vector<std::string> imageList;
            int imageListIndex;
            float duration;
            
            bool play = true;
        
            void load();
        };
    }
}

