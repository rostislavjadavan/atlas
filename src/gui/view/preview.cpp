#include "preview.hpp"
#include "../../core/app.hpp"

void atlas::gui::view::Preview::draw(ofRectangle rect, int selectedLayer) {
    const shared_ptr<atlas::layer::Base> layer = atlas::core::App::instance().getLayerContainer()->getLayer(selectedLayer);
    
    ofSetColor(0, 0, 0);
    ofDrawRectangle(rect);
    
    if (layer->getLayerType() != atlas::layer::LAYER_TYPE_EMPTY) {
        ofSetColor(255, 255, 255);
        layer->getFrame()->draw(rect);
    }
}
