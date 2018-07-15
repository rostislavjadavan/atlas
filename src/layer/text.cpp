#include "text.hpp"

void atlas::layer::Text::setup(const int layerIndex,const atlas::core::AppSettings &settings) {
    FboCanvas::setup(layerIndex, settings);
    this->size = 50;
    this->lineHeight = 55;
    this->letterSpacing = 1;
    memset(this->text, 0, sizeof this->text);
    memset(this->fontName, 0, sizeof this->fontName);
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
    if (ImGui::TreeNode("font properties")) {
        ImGui::InputInt("Size", &this->size);
        ImGui::InputText("Font filename (.ttf)", this->fontName, 256);
        ImGui::SameLine();
        if (ImGui::Button("LOAD")) {
            this->font.load(std::string(this->fontName), this->size);
        }
        ImGui::TreePop();
    }
}
