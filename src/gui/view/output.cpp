#include "output.hpp"
#include "../../core/app.hpp"

void atlas::gui::view::Output::draw(ofRectangle rect) {
    ofSetColor(255, 255, 255);
    atlas::core::App::instance().getLayerCompositor()->getFrame()->draw(rect);
}
