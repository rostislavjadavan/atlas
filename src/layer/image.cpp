#include "image.hpp"

void atlas::layer::Image::setup(const int layerIndex,const atlas::core::AppSettings &settings) {
    FboCanvas::setup(layerIndex, settings);
    this->mediaSelector.allowExt("jpg");
    this->mediaSelector.allowExt("png");
}

void atlas::layer::Image::update(const double delta) {
    this->fbo->begin();
    ofSetColor(255, 255, 255);
    ofClear(0, 0, 0, 0);
    
    if (this->preloader.getStatus() == atlas::layer::libs::ImagePreloader::PREPARED) {
        this->image.setFromPixels(*this->preloader.get().get());
    }
    
    if (this->image.isAllocated()) {
        this->drawTexture(this->image.getTexture());
    }
    
    this->fbo->end();
}

void atlas::layer::Image::gui() {
    ImGui::Text("%s", this->mediaSelector.getSelected().getFileName().c_str());
    if (this->mediaSelector.draw()) {
        this->load();
    }

    ImGui::Separator();
    this->partials.baseLayerPropsGui(props.index);
    
    this->partials.bpmLayerPropsGui(props.index);
}

void atlas::layer::Image::load() {
    this->preloader.preload(this->mediaSelector.getSelected().getAbsolutePath());
}

json atlas::layer::Image::saveJson() {
    json j;
    j["layer_type"] = this->getLayerType();
    j["props"] = this->props.saveJson();
    j["path"] = this->mediaSelector.getSelected().getAbsolutePath();
    return j;
}

void atlas::layer::Image::loadJson(const json &j) {
    if (j.count("props") > 0) {
        this->props.loadJson(j["props"]);
    }
    if (j.count("path") > 0) {
        this->mediaSelector.setSelected(j["path"]);
        this->load();
    }
}
