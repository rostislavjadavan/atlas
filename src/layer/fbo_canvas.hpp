#pragma once

#include "base.hpp"

namespace atlas {
    namespace layer {
        class FboCanvas : public Base {
        public:
            void setup(const int layerIndex, const atlas::core::AppSettings &settings);
            void update(const double delta) { }
            const std::shared_ptr<ofFbo>& getFrame();
            void gui() { }
            
        protected:
            int layerIndex;
            
            LayerDrawMode layerDrawMode;
            void drawTexture(const ofTexture &tex);
            
            std::shared_ptr<ofFbo> fbo;
        };
    }
}
