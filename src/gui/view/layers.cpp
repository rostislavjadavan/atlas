#include "layers.hpp"
#include "../../core/app.hpp"
#include <memory>

void atlas::gui::view::Layers::draw(ofRectangle rect, Events events) {
    const std::shared_ptr<atlas::core::LayerContainer> container = atlas::core::App::instance().getLayerContainer();
    
    const float tileSizeX = rect.width / container->NUM_LAYERS_X;
    const float tileSizeY = rect.height / container->NUM_LAYERS_Y;
    
    for (int y = 0; y < container->NUM_LAYERS_Y; y++) {
        for (int x = 0; x < container->NUM_LAYERS_X; x++) {
            ofRectangle rect(x * tileSizeX, y * tileSizeY, tileSizeX, tileSizeY);
            const int layerIndex = y * container->NUM_LAYERS_X + x;
            
            ofSetColor(66);
            if (rect.inside(events.mouseX, events.mouseY)) {
                ofSetColor(215, 215, 215);
                if (events.mouseButton == MOUSE_BUTTON_LEFT) {
                    this->selectedLayer = layerIndex;
                }
            }
            
            if (layerIndex == this->selectedLayer) {
                ofSetColor(255, 240, 40);
            }
            
            ofDrawRectangle(rect);
            
            ofRectangle rectInside(x * tileSizeX + 1, y * tileSizeY + 1, tileSizeX - 2, tileSizeY - 2);
            const std::shared_ptr<atlas::layer::Base> layer = container->getLayer(layerIndex);
            
            if (layer->getLayerType() == atlas::layer::LAYER_TYPE_EMPTY) {
                ofSetColor(0, 0, 0);
                ofDrawRectangle(rectInside);
            } else {
                ofSetColor(255, 255, 255);
                layer->getFrame()->draw(rectInside);
            }
        }
    }
}

int atlas::gui::view::Layers::getSelectedLayer() {
    return this->selectedLayer;
}
