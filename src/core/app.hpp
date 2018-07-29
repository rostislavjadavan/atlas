#pragma once

#include "app_settings.hpp"
#include "output_window.hpp"
#include "layer_container.hpp"
#include "layer_compositor.hpp"
#include "libs/of.hpp"
#include "libs/ofxBeat/ofxBeat.h"
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
            
            void setMainApp(const std::shared_ptr<ofBaseApp> &mainApp) {
                this->mainApp = mainApp;
            }
            
            const std::shared_ptr<ofAppBaseWindow>& getMainWindow() {
                return this->mainWindow;
            }
            
            const std::shared_ptr<OutputWindow>& getOutputWindow() {
                return this->outputWindow;
            }
            
            const std::shared_ptr<LayerContainer>& getLayerContainer() {
                return this->container;
            }
            
            const std::shared_ptr<LayerCompositor>& getLayerCompositor() {
                return this->compositor;
            }
            
            const std::shared_ptr<ofFbo>& getFrameFromLayer(int index) {
                return this->container->getLayer(index)->getFrame();
            }
            
            const std::shared_ptr<ofxBeat>& getBeatDetector() {
                return this->beatDetector;
            }
            
            AppSettings settings;
            
        protected:
            App() {}
            ~App() {}
            
            std::shared_ptr<ofAppBaseWindow> mainWindow;
            std::shared_ptr<OutputWindow> outputWindow;
            std::shared_ptr<ofBaseApp> mainApp;
            std::shared_ptr<LayerCompositor> compositor;
            std::shared_ptr<LayerContainer> container;
            std::shared_ptr<ofxBeat> beatDetector;
        };
        
    }
}
