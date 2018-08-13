#include "gif.hpp"

void atlas::layer::Gif::setup(const int layerIndex,const atlas::core::AppSettings &settings) {
    FboCanvas::setup(layerIndex, settings);
    this->mediaSelector.allowExt("gif");
}

void atlas::layer::Gif::update(const double delta) {
    this->fbo->begin();
    ofSetColor(255, 255, 255);
    ofClear(0, 0, 0, 0);
    
    if (this->preloader.getStatus() == atlas::layer::libs::GifPreloader::PREPARED) {
        this->currentGif = this->preloader.get();
    }
    
    if (this->currentGif.use_count() > 0) {
        if ((int)this->frame > this->currentGif->getFrameCount()) {
            this->frame = 0;
        }
        
        this->drawTexture(*this->currentGif->getFrameTexture((int)this->frame));
        
        if (this->playGif) {
            this->frame += delta * (float)this->currentGif->getDelay((int)this->frame) / 1000.0f;
        }
        
        if (this->bpmFrame.enabled) {
            this->frame = this->bpmFrame.applyAdd(this->frame);
        }
    }
    
    this->fbo->end();
}

void atlas::layer::Gif::gui() {
    ImGui::Text("%s", this->mediaSelector.getSelected().getFileName().c_str());
    if (this->mediaSelector.draw()) {
        this->load();
    }
    
    if (this->currentGif.use_count() > 0) {
        if (!this->playGif) {
            if (ImGui::Button("PLAY")) {
                this->playGif = true;
            }
        } else {
            if (ImGui::Button("STOP")) {
                this->playGif = false;
            }
        }
    }
    
    ImGui::Separator();
    this->partials.baseLayerPropsGui(props.index);
    
    ImGui::Checkbox("bpm frame", &this->bpmFrame.enabled);
    ImGui::Combo("bpm frame modify by", &this->bpmFrame.modifiedBy, atlas::layer::IMGUI_COMBO_BPM_MOFIFY_BY_LIST);
    ImGui::SliderFloat("bpm frame scale", &this->bpmFrame.scale, -100.0f, 100.0f);
    
    this->partials.bpmLayerPropsGui(props.index);
}

void atlas::layer::Gif::load() {
    this->preloader.preload(this->mediaSelector.getSelected().getAbsolutePath());
}

json atlas::layer::Gif::saveJson() {
    json j;
    j["layer_type"] = this->getLayerType();
    j["props"] = this->props.saveJson();
    j["path"] = this->mediaSelector.getSelected().getAbsolutePath();
    j["play"] = this->playGif;
    j["bpm_frame"] = this->bpmFrame.saveJson();
    return j;
}

void atlas::layer::Gif::loadJson(const json &j) {
    if (j.count("props") > 0) {
        this->props.loadJson(j["props"]);
    }
    if (j.count("path") > 0) {
        this->mediaSelector.setSelected(j["path"]);
        this->load();
    }
    if (j.count("play") > 0) {
        this->playGif = j["play"].get<bool>();
    }
    if (j.count("bpm_frame") > 0) {
        this->bpmFrame.loadJson(j["bpm_frame"]);
    }
}
