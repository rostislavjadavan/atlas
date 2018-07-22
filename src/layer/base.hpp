#pragma once

#include "common.hpp"
#include "core/app_settings.hpp"
#include "core/blend_shaders.hpp"
#include "libs/of.hpp"

namespace atlas {
    namespace layer {
        
        static const int LAYER_DRAW_MODE_ORIGINAL = 0;
        static const int LAYER_DRAW_MODE_STRETCH = 1;
        static const int LAYER_DRAW_MODE_FIT = 2;
        static const char *IMGUI_COMBO_LAYER_DRAW_MODES = "ORIGINAL\0STRETCH\0FIT\0";
        
        struct LayerProps {
            int index;
            float alpha;
            int x, y, width, height;
            int drawMode;
            int blendMode;
            bool disabledFromOutput;
            
            void init(int index, int width, int height) {
                this->index = index;
                this->alpha = 1.0f;
                this->x = 0;
                this->y = 0;
                this->width = width;
                this->height = height;
                this->drawMode = LAYER_DRAW_MODE_FIT;
                this->blendMode = atlas::core::BlendShaders::BLEND_MODE_ADD;
                this->disabledFromOutput = false;
            }
        };
        
        class Base {
        public:
            LayerProps props;
            
            virtual void setup(const int layerIndex, const atlas::core::AppSettings &settings) = 0;
            virtual void update(const double delta) = 0;
            virtual const std::shared_ptr<ofFbo>& getFrame() = 0;
            virtual void gui() = 0;
            virtual int getLayerType() = 0;
        };
    }
}
