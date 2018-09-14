#pragma once

#include "fbo_canvas.hpp"
#include "../gui/view/media_selector.hpp"
#include "libs/linear_timeline.hpp"

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
            
            int timeDisplay, timeHidden, timeAnimation;
            atlas::layer::libs::LinearTimeline lt;
            
            ofTrueTypeFont font;
            void loadFont();
        };
    }
}
