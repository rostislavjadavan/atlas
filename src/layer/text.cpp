#include "text.hpp"

void atlas::layer::Text::setup(const int layerIndex,const atlas::core::AppSettings &settings) {
    FboCanvas::setup(layerIndex, settings);
    this->size = 50;
    this->lineHeight = 55;
    this->letterSpacing = 1;
    memset(this->text, 0, sizeof this->text);
}

void atlas::layer::Text::update(const double delta) {
    this->fbo->begin();
    ofSetColor(255, 255, 255);
    ofClear(0, 0, 0, 255);
    
    if (this->font.isLoaded()) {
        this->font.setLetterSpacing(this->letterSpacing);
        this->font.setLineHeight(this->lineHeight);
        
        ofRectangle bb = this->font.getStringBoundingBox(std::string(this->text), 0, 0);
        this->font.drawString(std::string(this->text),
                              this->settings.compositorOutputWidth / 2 - bb.width / 2,
                              this->settings.compositorOutputHeight / 2 - bb.height / 2
                              );
    }
    this->fbo->end();
}

void atlas::layer::Text::gui() {
    ImGui::InputTextMultiline("Text", this->text, 1024);
    ImGui::InputFloat("Line height", &this->lineHeight);
    ImGui::InputFloat("Letter spacing", &this->letterSpacing);
    if (ImGui::InputInt("Size", &this->size)) {
        this->font.load(this->mediaSelector.getSelected().getAbsolutePath(), this->size);
    }
    ImGui::Text("%s", this->mediaSelector.getSelected().getFileName().c_str());
    if (this->mediaSelector.draw()) {
        this->font.load(this->mediaSelector.getSelected().getAbsolutePath(), this->size);
    }
}
