#pragma once

#include "base.hpp"

namespace atlas {
    namespace layer {
        class Empty : public Base {
        public:
            void setup(const int layerIndex, const atlas::core::AppSettings &settings);
            void update(const double delta) { }
            const std::shared_ptr<ofFbo>& getFrame() { return nullptr; }
            void gui();
        private:
            int layerIndex;
        };
    }
}
