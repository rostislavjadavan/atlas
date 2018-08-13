#include "gif_directory.hpp"

void atlas::layer::GifDirectory::setup(const int layerIndex, const atlas::core::AppSettings &settings) {
    FboCanvas::setup(layerIndex, settings);
    this->mediaSelector.setMode(atlas::gui::view::DIR_SELECT);
}

void atlas::layer::GifDirectory::update(double delta) {
    if (this->gifList.size() > 0 && this->preloadQueue.size() < PRELOAD_QUEUE_SIZE && this->preloader.getStatus() == atlas::layer::libs::GifPreloader::WAITING) {
        this->preloader.preload(this->gifList.at(this->gifListIndex));
        
        this->gifListIndex++;
        if (this->gifListIndex >= this->gifList.size()) {
            this->gifListIndex = 0;
        }
    }
    
    if (this->preloader.getStatus() == atlas::layer::libs::GifPreloader::PREPARED) {
        this->preloadQueue.push(this->preloader.get());
    }
    
    if (this->currentGif.use_count() == 0 && this->preloadQueue.size() > 0) {
        this->currentGif = this->preloadQueue.front();
        this->preloadQueue.pop();
    }
    
    this->fbo->begin();
    ofSetColor(255, 255, 255);
    ofClear(0, 0, 0, 0);
    
    if (this->currentGif.use_count() > 0) {
        if ((int)this->frame > this->currentGif->getFrameCount() || this->nextGifTrigger > 100.0f) {
            if (this->preloadQueue.size() > 0) {
                this->currentGif = this->preloadQueue.front();
                this->preloadQueue.pop();
            }
            this->frame = 0;
            this->nextGifTrigger = 0.0f;
        }
        
        this->drawTexture(*this->currentGif->getFrameTexture((int)this->frame));
        
        if (this->playGif) {
            this->frame += delta * (float)this->currentGif->getDelay((int)this->frame) / 1000.0f;
        }
        
        if (this->bpmFrame.enabled) {
            this->frame = this->bpmFrame.applyAdd(this->frame);
        }
        
        if (bpmNextGif.enabled) {
            this->nextGifTrigger = this->bpmNextGif.applyAdd(this->nextGifTrigger);
        }
    }
    
    this->fbo->end();
}

void atlas::layer::GifDirectory::gui() {
    ImGui::Text("%s", this->mediaSelector.getSelected().getFileName().c_str());
    if (this->mediaSelector.draw()) {
        std::queue<std::shared_ptr<GifDecoder>>().swap(this->preloadQueue);
        this->gifListIndex = 0;
        this->gifList.clear();
        this->load();
    }
    
    if (this->gifList.size() > 0 && this->currentGif.use_count() > 0) {
        ImGui::Text("Now playing %i/%i", this->gifListIndex + 1 - PRELOAD_QUEUE_SIZE, (int)this->gifList.size());
        
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
    
    ImGui::Checkbox("bpm next gif", &this->bpmNextGif.enabled);
    ImGui::Combo("bpm next gif modify by", &this->bpmNextGif.modifiedBy, atlas::layer::IMGUI_COMBO_BPM_MOFIFY_BY_LIST);
    ImGui::SliderFloat("bpm next gif scale", &this->bpmNextGif.scale, 0.0f, 100.0f);
    
    this->partials.bpmLayerPropsGui(props.index);
}

void atlas::layer::GifDirectory::load() {
    ofDirectory dir;
    
    dir.open(this->mediaSelector.getSelected().getAbsolutePath());
    dir.allowExt("gif");
    
    const int size = (int)dir.listDir();
    if (size > 0) {
        this->gifList.clear();
        for (int i = 0; i < dir.size(); i ++) {
            this->gifList.push_back(dir.getPath(i));
        }
        this->gifListIndex = 0;
    }
}

json atlas::layer::GifDirectory::saveJson() {
    json j;
    j["layer_type"] = this->getLayerType();
    j["props"] = this->props.saveJson();
    j["path"] = this->mediaSelector.getSelected().getAbsolutePath();
    j["play"] = this->playGif;
    j["bpm_frame"] = this->bpmFrame.saveJson();
    j["bpm_next_gif"] = this->bpmNextGif.saveJson();
    return j;
}

void atlas::layer::GifDirectory::loadJson(const json &j) {
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
    if (j.count("bpm_next_gif") > 0) {
        this->bpmNextGif.loadJson(j["bpm_next_gif"]);
    }
}
