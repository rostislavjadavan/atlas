#pragma once

#include "libs/of.hpp"
#include "core/layer_container.hpp"
#include <memory>

namespace atlas {
    namespace core {
        
        class App {
        public:
            static App& i() {
                static App myInstance;
                return myInstance;
            }
            
            App(App const&) = delete;
            App(App&&) = delete;
            App& operator=(App const&) = delete;
            App& operator=(App &&) = delete;
            
            static const int APP_WIDTH = 1280;
            static const int APP_HEIGHT = 800;
            
            void runOfApp();
            
            const std::shared_ptr<ofAppBaseWindow>& getMainWindow() {
                return this->mainWindow;
            }
            
             /*std::shared_ptr<ApplicationSettings> pSettings;
             std::shared_ptr<LayerManager> pLayerManager;
             std::shared_ptr<LayerCompositor> pLayerCompositor;*/
            
        protected:
            App() {}
            ~App() {}
            
            std::shared_ptr<ofAppBaseWindow> mainWindow;
        };
        
    }
}
