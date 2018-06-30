#include "app.hpp"
#include "ofApp.h"

const int atlas::core::App::APP_WIDTH;
const int atlas::core::App::APP_HEIGHT;

void atlas::core::App::runOfApp() {
    ofGLFWWindowSettings settings;
    settings.width = APP_WIDTH;
    settings.height = APP_HEIGHT;
    
    this->mainWindow = ofCreateWindow(settings);

    shared_ptr<ofApp> mainApp(new ofApp);    
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
}
