#include "preview.hpp"
#include "../../core/app.hpp"

void atlas::gui::view::Preview::draw(ofRectangle rect, int selectedLayer) {
    const shared_ptr<ofFbo> frame = atlas::core::App::instance().getFrameFromLayer(selectedLayer);
    if (frame == nullptr) {
        ofSetColor(0, 0, 0);
        ofDrawRectangle(rect);
    } else {
        ofSetColor(255, 255, 255);
        frame->draw(rect);
    }
}
