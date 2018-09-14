#include "text.hpp"

void atlas::layer::Text::setup(const int layerIndex,const atlas::core::AppSettings &settings) {
    FboCanvas::setup(layerIndex, settings);
    this->size = 50;
    this->lineHeight = 55;
    this->letterSpacing = 1;
    this->timeDisplay = 10;
    this->timeAnimation = 5;
    this->timeHidden = 10;
    memset(this->text, 0, sizeof this->text);
    this->mediaSelector.allowExt("ttf");
    
    this->lt.add(ofVec2f(0, 0.0));
    this->lt.add(ofVec2f(this->timeAnimation, 1.0));
    this->lt.add(ofVec2f(this->timeDisplay, 1.0));
    this->lt.add(ofVec2f(this->timeAnimation, 0.0));
    this->lt.add(ofVec2f(this->timeHidden, 0.0));
}

void atlas::layer::Text::update(const double delta) {
    this->lt.update(delta);
    
    this->fbo->begin();
    ofSetColor(255, 255, 255, this->lt.get() * 255);
    ofClear(0, 0, 0, 0);
    
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
        this->loadFont();
    }
    ImGui::Text("%s", this->mediaSelector.getSelected().getFileName().c_str());
    if (this->mediaSelector.draw()) {
        this->loadFont();
    }
    ImGui::Separator();
    ImGui::InputInt("Display time", &this->timeDisplay);
    ImGui::InputInt("Hidden time", &this->timeHidden);
    ImGui::InputInt("Fade in/out time", &this->timeAnimation);
    ImGui::Separator();
    this->partials.baseLayerPropsGui(props.index);
    this->partials.bpmLayerPropsGui(props.index);
    
    this->lt.set(1, ofVec2f(this->timeAnimation, 1.0));
    this->lt.set(2, ofVec2f(this->timeDisplay, 1.0));
    this->lt.set(3, ofVec2f(this->timeAnimation, 0.0));
    this->lt.set(4, ofVec2f(this->timeHidden, 0.0));
}

void atlas::layer::Text::loadFont() {
    this->font.load(this->mediaSelector.getSelected().getAbsolutePath(), this->size);
}

json atlas::layer::Text::saveJson() {
    json j;
    j["layer_type"] = this->getLayerType();
    j["props"] = this->props.saveJson();
    j["path"] = this->mediaSelector.getSelected().getAbsolutePath();
    j["text"] = this->text;
    j["size"] = this->size;
    j["line_height"] = this->lineHeight;
    j["letter_spacing"] = this->letterSpacing;
    j["time_animation"] = this->timeAnimation;
    j["time_display"] = this->timeDisplay;
    j["time_hidden"] = this->timeHidden;
    
    return j;
}

void atlas::layer::Text::loadJson(const json &j) {
    if (j.count("props") > 0) {
        this->props.loadJson(j["props"]);
    }
    if (j.count("text")) {
        strncpy(this->text, j["text"].get<std::string>().c_str(), 1023);
        this->text[1023] = '\0';
    }
    if (j.count("size")) {
        this->size = j["size"].get<int>();
    }
    if (j.count("line_height")) {
        this->lineHeight = j["line_height"].get<float>();
    }
    if (j.count("letter_spacing")) {
        this->letterSpacing = j["letter_spacing"].get<float>();
    }
    if (j.count("path") > 0) {
        this->mediaSelector.setSelected(j["path"]);
        this->loadFont();
    }
    if (j.count("time_animation")) {
        this->timeAnimation = j["time_animation"].get<float>();
    }
    if (j.count("time_display")) {
        this->timeDisplay = j["time_display"].get<float>();
    }
    if (j.count("time_hidden")) {
        this->timeHidden = j["time_hidden"].get<float>();
    }
}
