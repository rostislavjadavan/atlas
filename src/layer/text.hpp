#pragma once

#include "fbo_canvas.hpp"

namespace atlas {
    namespace layer {
        class Text : public FboCanvas {
        public:
            void setup(const int layerIndex,const atlas::core::AppSettings &settings);
            void update(const double delta);
            void gui();
            int getLayerType() {
                return LAYER_TYPE_TEXT;
            }
            
        protected:
            char text[1024];
            int size;
            float lineHeight, letterSpacing;
            
            char fontName[256];
            int timeDisplay, timeHidden, timeAnimation;
            
            ofTrueTypeFont font;
        };
    }
}
