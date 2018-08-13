#pragma once

#include "fbo_canvas.hpp"
#include "../gui/view/media_selector.hpp"

namespace atlas {
    namespace layer {
        class Text : public FboCanvas {
        public:
            void setup(const int layerIndex,const atlas::core::AppSettings &settings);
            void update(const double delta);
            void gui();
            int getLayerType() {
                return atlas::layer::LAYER_TYPE_TEXT;
            }
            json saveJson();
            void loadJson(const json &j);
            
        protected:
            char text[1024];
            int size;
            float lineHeight, letterSpacing;
            
            atlas::gui::view::MediaSelector mediaSelector;
            
            // TODO: implement in separate timeline class
            int timeDisplay, timeHidden, timeAnimation;
            
            ofTrueTypeFont font;
            void loadFont();
        };
    }
}
