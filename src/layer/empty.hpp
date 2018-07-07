#pragma once

#include "base.hpp"

namespace atlas {
    namespace layer {
        class Empty : public Base {
        public:
            void setup(const atlas::core::AppSettings &settings) { }
            void update(double delta) { }
            const std::shared_ptr<ofFbo>& getFrame() { return nullptr; }
            void renderGui();
        };
    }
}
