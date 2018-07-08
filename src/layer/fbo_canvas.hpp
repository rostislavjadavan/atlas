#pragma once

#include "base.hpp"

namespace atlas {
    namespace layer {
        class FboCanvas : public Base {
        public:
            void setup(const atlas::core::AppSettings &settings);
            void update(double delta) { }
            const std::shared_ptr<ofFbo>& getFrame();
            void gui() { }
            
        protected:
            LayerDrawMode layerDrawMode;
            void drawTexture(const ofTexture &tex);
            std::shared_ptr<ofFbo> fbo;
        };
    }
}
