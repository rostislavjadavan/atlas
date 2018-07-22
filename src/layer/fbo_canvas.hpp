#pragma once

#include "base.hpp"
#include "../gui/view/properties_partials.hpp"

namespace atlas {
    namespace layer {
        class FboCanvas : public Base {
        public:
            void setup(const int layerIndex, const atlas::core::AppSettings &settings);
            void update(const double delta) { }
            const std::shared_ptr<ofFbo>& getFrame();
            void gui() { }
            int getLayerType() {
                return LAYER_TYPE_EMPTY;
            }
            
        protected:
            atlas::core::AppSettings settings;
            std::shared_ptr<ofFbo> fbo;
            
            void drawTexture(const ofTexture &tex);
            
            atlas::gui::view::PropertiesPartials partials;
        };
    }
}
