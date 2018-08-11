#include "preview.hpp"
#include "../../core/app.hpp"

void atlas::gui::view::Preview::draw(ofRectangle rect, int selectedLayer) {
    const shared_ptr<ofFbo> frame = atlas::core::App::instance().getFrameFromLayer(selectedLayer);
    
    ofSetColor(0, 0, 0);
    ofDrawRectangle(rect);
    
    if (frame != nullptr) {
        ofSetColor(255, 255, 255);
        frame->draw(rect);
    }
}
