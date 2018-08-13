#pragma once

#include "constants.hpp"
#include "../core/app_settings.hpp"
#include "../core/blend_shaders.hpp"
#include "../core/bpm_modifier.hpp"
#include "../libs/json.hpp"
#include "../libs/of.hpp"

namespace atlas {
    namespace layer {
        
        static const char *IMGUI_COMBO_LAYER_DRAW_MODES = "ORIGINAL\0STRETCH\0FIT\0";
        static const char *IMGUI_COMBO_BPM_MOFIFY_BY_LIST = "KICK\0SNARE\0HIHAT\0";
        
        struct LayerProps {
            int index;
            float alpha;
            int x, y, width, height;
            int drawMode;
            int blendMode;
            bool disabledFromOutput;
            
            atlas::core::BpmModifier bpmAlpha, bpmScale;
            
            void init(int index, int width, int height) {
                this->index = index;
                this->alpha = 1.0f;
                this->x = 0;
                this->y = 0;
                this->width = width;
                this->height = height;
                this->drawMode = atlas::core::LAYER_DRAW_MODE_FIT;
                this->blendMode = atlas::core::BlendShaders::BLEND_MODE_ADD;
                this->disabledFromOutput = false;
            }
            
            const json saveJson() {
                json j;
                j["index"] = this->index;
                j["alpha"] = this->alpha;
                j["x"] = this->x;
                j["y"] = this->y;
                j["width"] = this->width;
                j["height"] = this->height;
                j["draw_mode"] = this->drawMode;
                j["blend_mode"] = this->blendMode;
                j["disable_from_output"] = this->disabledFromOutput;
                j["bpm_alpha"] = this->bpmAlpha.saveJson();
                j["bpm_scale"] = this->bpmScale.saveJson();                
                return j;
            }
            
            bool loadJson(const json &j) {
                if (j.count("index") > 0) {
                    this->index = j["index"].get<int>();
                }
                if (j.count("alpha") > 0) {
                    this->alpha = j["alpha"].get<float>();
                }
                if (j.count("x") > 0) {
                    this->x = j["x"].get<int>();
                }
                if (j.count("y") > 0) {
                    this->y = j["y"].get<int>();
                }
                if (j.count("width") > 0) {
                    this->width = j["width"].get<int>();
                }
                if (j.count("height") > 0) {
                    this->height = j["height"].get<int>();
                }
                if (j.count("draw_mode") > 0) {
                    this->drawMode = j["draw_mode"].get<int>();
                }
                if (j.count("blend_mode") > 0) {
                    this->blendMode = j["blend_mode"].get<int>();
                }
                if (j.count("disable_from_output") > 0) {
                    this->disabledFromOutput = j["disable_from_output"].get<bool>();
                }
                if (j.count("bpm_alpha") > 0) {
                    this->bpmAlpha.loadJson(j["bpm_alpha"]);
                }
                if (j.count("bpm_scale") > 0) {
                    this->bpmScale.loadJson(j["bpm_scale"]);
                }
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
            virtual json saveJson() = 0;
            virtual void loadJson(const json &j) = 0;
        };
    }
}
