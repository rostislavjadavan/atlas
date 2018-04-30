#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

std::shared_ptr<ofAppBaseWindow> mainWindow;

int main( ){
    ofGLFWWindowSettings settings;
    settings.width = 1280;
    settings.height = 800;
    settings.resizable = false;
    mainWindow = ofCreateWindow(settings);
    shared_ptr<ofApp> mainApp(new ofApp);
    
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
}
