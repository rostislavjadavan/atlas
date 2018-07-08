#pragma once

#include "core/app_settings.hpp"
#include "libs/of.hpp"

namespace atlas {
    namespace layer {
        
        enum LayerDrawMode {
            ORIGINAL, STRETCH, FIT
        };
        
        class Base {
        public:
            virtual void setup(const atlas::core::AppSettings &settings) = 0;
            virtual void update(double delta) = 0;
            virtual const std::shared_ptr<ofFbo>& getFrame() = 0;
            virtual void gui() = 0;
        private:
            
        };
    }
}
