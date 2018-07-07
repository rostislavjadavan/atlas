#include "layers.hpp"
#include "../../core/app.hpp"
#include <memory>

void atlas::gui::Layers::draw(ofRectangle rect, Events events) {
    std::shared_ptr<atlas::core::LayerContainer> container = atlas::core::App::instance().getLayerContainer();
    
    const int tileSizeX = rect.width / container->NUM_LAYERS_X - 2;
    const int tileSizeY = rect.height / container->NUM_LAYERS_Y - 2;
    
    for (int y = 0; y < container->NUM_LAYERS_Y; y++) {
        for (int x = 0; x < container->NUM_LAYERS_X; x++) {
            ofRectangle rect(x * (tileSizeX + 2) + 2, y * (tileSizeY + 2) + 2, tileSizeX, tileSizeY);
            
            ofSetColor(0, 0, 0);
            if (rect.inside(events.mouseX, events.mouseY)) {
                if (events.mouseButton == MOUSE_BUTTON_LEFT) {
                    ofSetColor(255, 0, 0);
                } else
                ofSetColor(0, 255, 0);
            }
            ofDrawRectangle(rect);
        }
    }
}
