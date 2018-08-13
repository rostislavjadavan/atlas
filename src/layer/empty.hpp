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
            int getLayerType() {
                return atlas::layer::LAYER_TYPE_EMPTY;
            }
            json saveJson() {
                json j;
                j["layer_type"] = this->getLayerType();
                return j;
            }
            void loadJson(const json &j) { }
        };
    }
}
