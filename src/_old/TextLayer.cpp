#include "TextLayer.h"

TextLayer::TextLayer(int width, int height): FboLayer(width, height) {
    this->size = 50;
    this->lineHeight = 55;
    this->letterSpacing = 1;
    memset(this->text, 0, sizeof this->text);
    memset(this->fontName, 0, sizeof this->fontName);
}

TextLayer::~TextLayer() {
    
}

void TextLayer::displayGui() {
    ImGui::PushID(this->getLayerIdString().c_str());
    if (ImGui::CollapsingHeader((this->getName() + " (" + this->getLayerIdString() + ")").c_str())) {
        this->commonGui();
        this->customGui();
    }
    ImGui::PopID();
}

void TextLayer::update() {
    const float delta = this->getDelta();
    
    this->updateBegin();
    if (this->font.isLoaded()) {
        this->font.setLetterSpacing(this->letterSpacing);
        this->font.setLineHeight(this->lineHeight);
        
        ofRectangle bb = this->font.getStringBoundingBox(std::string(this->text), 0, 0);
        this->font.drawString(std::string(this->text), this->layerInfo.width / 2 - bb.width / 2, this->layerInfo.height / 2 - bb.height / 2);
    }
    this->updateEnd();
}

void TextLayer::customGui() {
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
