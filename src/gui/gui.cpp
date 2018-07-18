#include "gui.hpp"
#include "gui_theme.hpp"

void atlas::gui::Gui::setup() {
    ofSetWindowTitle(this->settings.appName);
    
    this->events.mouseButton = MOUSE_BUTTON_NONE;
    
    ofAddListener(ofEvents().mousePressed, this, &atlas::gui::Gui::onMousePressed);
    ofAddListener(ofEvents().mouseReleased, this, &atlas::gui::Gui::onMouseReleased);
    ofAddListener(ofEvents().mouseMoved, this, &atlas::gui::Gui::onMouseMove);
    ofAddListener(ofEvents().keyReleased, this, &atlas::gui::Gui::onKeyReleased);
    ofAddListener(ofEvents().keyPressed, this, &atlas::gui::Gui::onKeyPressed);
    
    this->gui.setup();
    
    GuiTheme::apply();
}

void atlas::gui::Gui::draw() {
    ofClear(100);
    this->gui.begin();
    
    const int width = ofGetWidth();
    const int height = ofGetHeight();
    const float compositorRatio = atlas::core::App::instance().settings.getHeightToWidthRatio();
    
    //
    // Layers
    //
    const float layersWidth = width / 3;
    const float layerHeight = layersWidth * compositorRatio;
    
    this->layersView.draw(ofRectangle(0, 0, layersWidth - 1, layerHeight), this->events);
    this->selectedLayer = this->layersView.getSelectedLayer();
    
    //
    // Preview
    //
    const float previewWidth = width / 3;
    const float previewHeight = previewWidth * compositorRatio;
    
    this->previewView.draw(ofRectangle(layersWidth, 0, previewWidth - 1, previewHeight), this->selectedLayer);
    
    //
    // Output
    //
    const float outputWidth = width / 3;
    const float outputHeight = outputWidth * compositorRatio;
    
    this->outputView.draw(ofRectangle(layersWidth + previewWidth, 0, outputWidth, outputHeight));
    
    //
    // Properties
    //
    this->propertiesView.draw(ofRectangle(0, layerHeight + 1, layersWidth + previewWidth - 1, height - layerHeight), this->selectedLayer);
    
    //
    // System
    //
    this->systemView.draw(ofRectangle(layersWidth + previewWidth, layerHeight + 1, outputWidth, height - layerHeight));
    
    this->gui.end();
}

void atlas::gui::Gui::disableSelections() {
    this->layersView.disableSelections();
}

void atlas::gui::Gui::enableSelections() {
    this->layersView.enableSelections();
}

void atlas::gui::Gui::onKeyReleased(ofKeyEventArgs& event) {
    // TODO
}

void atlas::gui::Gui::onKeyPressed(ofKeyEventArgs& event) {
    // TODO
}

void atlas::gui::Gui::onMousePressed(ofMouseEventArgs& event) {
    this->events.mouseButton = event.button;
}

void atlas::gui::Gui::onMouseReleased(ofMouseEventArgs& event) {
    this->events.mouseButton = MOUSE_BUTTON_NONE;
}

void atlas::gui::Gui::onMouseMove(ofMouseEventArgs& event) {
    this->events.mouseX = event.x;
    this->events.mouseY = event.y;
}
