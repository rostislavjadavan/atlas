#pragma once

#include "ofMain.h"
#include "core/ApplicationSettings.h"
#include "core/LayerManager.h"
#include "core/LayerCompositor.h"
#include "output/OutputWindow.h"

class Application {
    
public:
    static Application& Instance() {
        static Application myInstance;
        return myInstance;
    }
    
    Application(Application const&) = delete;
    Application(Application&&) = delete;
    Application& operator=(Application const&) = delete;
    Application& operator=(Application &&) = delete;

    std::shared_ptr<ofAppBaseWindow> mainWindow;
    std::shared_ptr<ApplicationSettings> pSettings;
    std::shared_ptr<LayerManager> pLayerManager;
    std::shared_ptr<LayerCompositor> pLayerCompositor;
    
protected:
    Application() {
    }
    
    ~Application() {
    }

};
