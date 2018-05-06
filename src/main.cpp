#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"
#include "core/Application.h"

int main( ){
    ofGLFWWindowSettings settings;
    settings.width = 1280;
    settings.height = 800;
    Application::Instance().mainWindow = ofCreateWindow(settings);
    shared_ptr<ofApp> mainApp(new ofApp);
    
    ofRunApp(Application::Instance().mainWindow, mainApp);
    ofRunMainLoop();
}
