#include "app.hpp"

void atlas::core::App::setup() {
    this->container = std::make_shared<LayerContainer>();
    this->compositor = std::make_shared<LayerCompositor>(this->container, this->settings);
    
    this->outputWindow = std::make_shared<OutputWindow>();
    this->outputWindow->init();
}

void atlas::core::App::update() {
    this->compositor->update();
}

