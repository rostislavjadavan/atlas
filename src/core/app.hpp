#pragma once

#include "libs/of.hpp"
#include "core/app_settings.hpp"
#include "core/layer_container.hpp"
#include "core/layer_compositor.hpp"
#include <memory>

namespace atlas {
    namespace core {
        
        class App {
        public:
            static App& instance() {
                static App myInstance;
                return myInstance;
            }
            
            App(App const&) = delete;
            App(App&&) = delete;
            App& operator=(App const&) = delete;
            App& operator=(App &&) = delete;
            void setup();
            void update();
            
            void setMainWindow(const std::shared_ptr<ofAppBaseWindow> &mainWindow) {
                this->mainWindow = mainWindow;
            }
            
            const std::shared_ptr<ofAppBaseWindow>& getMainWindow() {
                return this->mainWindow;
            }
            
            const std::shared_ptr<LayerContainer>& getLayerContainer() {
                return this->container;
            }
            
            const std::shared_ptr<LayerCompositor>& getLayerCompositor() {
                return this->compositor;
            }
            
            AppSettings settings;
            
        protected:
            App() {}
            ~App() {}
            
            std::shared_ptr<ofAppBaseWindow> mainWindow;
            std::shared_ptr<LayerCompositor> compositor;
            std::shared_ptr<LayerContainer> container;
        };
        
    }
}
