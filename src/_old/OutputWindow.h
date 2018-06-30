#pragma once

#include "ofMain.h"
#include "ofxImGui.h"
#include "ofAppGLFWWindow.h"
#include "ofOutputApp.h"
#include "../core/Application.h"
#include <vector>
#include <string>

class OutputWindow {
public:
    void init();
    void displayGui();
    
private:
    
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
