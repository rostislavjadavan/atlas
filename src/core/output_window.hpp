#pragma once

#include "../libs/of.hpp"
#include "../ofOutputApp.h"
#include <vector>

namespace atlas {
    namespace core {
        class OutputWindow {
        public:
            void init();
            void gui();
            
            protected:
            
            struct MonitorInfo {
                bool isPrimary;
                int width, height;
                int vx, vy;
                std::string name;
                
                std::string getTitle() {
                    return name + " (" + std::to_string(this->width) + "x" + std::to_string(this->height) + ")";
                }
            };
            
            std::vector<MonitorInfo> monitors;
            void open(MonitorInfo *mi);
            
            std::shared_ptr<ofAppBaseWindow> window;
        };
    }
}
