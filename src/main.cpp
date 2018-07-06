#include "core/app.hpp"
#include "ofApp.h"

static const int APP_WIDTH = 1280;
static const int APP_HEIGHT = 800;

int main() {
    ofGLFWWindowSettings settings;
    settings.width = APP_WIDTH;
    settings.height = APP_HEIGHT;
    
    std::shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    atlas::core::App::instance().setMainWindow(mainWindow);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
}
