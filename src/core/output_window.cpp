#include "output_window.hpp"
#include "app.hpp"

void atlas::core::OutputWindow::init() {
    /*
    int count;
    GLFWmonitor **monitors = glfwGetMonitors(&count);
    
    for (int i = 0; i < count; i++) {
        GLFWmonitor *monitor = monitors[i];
        const GLFWvidmode *desktopMode = glfwGetVideoMode(monitor);
        
        if (desktopMode) {
            MonitorInfo mi;
            mi.name = glfwGetMonitorName(monitor);
            mi.width = desktopMode->width;
            mi.height = desktopMode->height;
            glfwGetMonitorPos(monitor, &mi.vx, &mi.vy);
            mi.isPrimary = (i == 0);
            this->monitors.push_back(mi);
            
            ofLog(OF_LOG_NOTICE) << "[OutputWindow] " << mi.name << ": " << mi.width << "x" << mi.height << " (pos: " << mi.vx << ", " << mi.vy << ")" << (mi.isPrimary ? " primary" : "");
        }
    }
    */
}

void atlas::core::OutputWindow::gui() {
    /*
    for (MonitorInfo mi: this->monitors) {
        ImGui::Text("%s", mi.getTitle().c_str());
        if (!mi.isPrimary && !this->window) {
            ImGui::SameLine();
            if (ImGui::Button("OPEN")) {
                this->open(&mi);
                
            }
        }
    }
    if (this->window) {
        if (ImGui::Button("CLOSE")) {
            this->window->setWindowShouldClose();
            this->window.reset();
        }
    }
    if (ImGui::Button("REFRESH")) {
        this->monitors.clear();
        this->init();
    }*/
}

void atlas::core::OutputWindow::open(MonitorInfo *mi) {
    /*ofGLFWWindowSettings wsettings;
    wsettings.resizable = false;
    wsettings.decorated = false;
    //wsettings.width = mi->width;
    //wsettings.height = mi->height;
    wsettings.setPosition(ofVec2f(mi->vx, mi->vy));
    wsettings.shareContextWith = App::instance().getMainWindow();
    
    this->window = ofCreateWindow(wsettings);
    this->window->setVerticalSync(false);
    this->window->toggleFullscreen();
    
    shared_ptr<ofOutputApp> outputApp(new ofOutputApp);
    ofRunApp(this->window, outputApp);*/
}
