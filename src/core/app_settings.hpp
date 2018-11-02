#pragma once

#include "../libs/json.hpp"
#include "../libs/of.hpp"

namespace atlas {
    namespace core {
        class AppSettings {
        public:
            int compositorOutputWidth = 800;
            int compositorOutputHeight = 600;
            
            float getHeightToWidthRatio() {
                return (float)this->compositorOutputHeight / (float)this->compositorOutputWidth;
            }
            
            void loadIfExists() {
                ofFile file;
                if (file.open(ofToDataPath("config/application.json"), ofFile::ReadOnly, false)) {
                    //try {
                        nlohmann::json config = nlohmann::json::parse(file.readToBuffer().getData());
                        
                        ofLogNotice() << "[AppSettings] loading application.json";
                        
                        if (config.count("compositor_output_width") > 0) {
                            this->compositorOutputWidth = config["compositor_output_width"].get<int>();
                        }
                        if (config.count("compositor_output_height") > 0) {
                            this->compositorOutputHeight = config["compositor_output_height"].get<int>();
                        }
                    /*} catch (const nlohmann::detail::parse_error &e) {
                        ofLogError() << "[AppSettings] error parsing application.json: " << e.what();
                    }*/
                } else {
                    ofLogError() << "[AppSettings] application.json does not exists";
                }
            }
        };
    }
}
