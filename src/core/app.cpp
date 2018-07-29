#include "app.hpp"

void atlas::core::App::setup() {
    this->container = std::make_shared<LayerContainer>();
    this->compositor = std::make_shared<LayerCompositor>(this->container, this->settings);
    
    this->outputWindow = std::make_shared<OutputWindow>();
    this->outputWindow->init();
    
    this->beatDetector = std::make_shared<ofxBeat>();
    ofSoundStreamSetup(0, 2, this->mainApp.get(), 44100, this->beatDetector->getBufferSize(), 4);
}

void atlas::core::App::update() {
    this->compositor->update();
    this->beatDetector->update(ofGetElapsedTimeMillis());
}

