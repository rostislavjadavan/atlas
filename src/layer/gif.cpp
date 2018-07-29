#include "gif.hpp"

void atlas::layer::Gif::setup(const int layerIndex,const atlas::core::AppSettings &settings) {
    FboCanvas::setup(layerIndex, settings);
    this->mediaSelector.allowExt("gif");
}

void atlas::layer::Gif::update(const double delta) {
    this->fbo->begin();
    ofSetColor(255, 255, 255);
    ofClear(0, 0, 0, 255);
    
    if (this->preloader.getStatus() == GifPreloader::PREPARED) {
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
        
    }
    
    this->fbo->end();
}

void atlas::layer::Gif::gui() {
    ImGui::Text("%s", this->mediaSelector.getSelected().getFileName().c_str());
    if (this->mediaSelector.draw()) {
        this->preloader.preload(this->mediaSelector.getSelected().getAbsolutePath());
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
}

