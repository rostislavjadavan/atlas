#include "GifLayer.h"

GifLayer::GifLayer(int width, int height): FboLayer(width, height) {
    frame = 0;
}

GifLayer::~GifLayer() {
    
}

void GifLayer::play() {
    this->playGif = true;
}

void GifLayer::stop() {
    this->playGif = false;
}

void GifLayer::displayGui() {
    ImGui::PushID(this->getLayerIdString().c_str());
    if (ImGui::CollapsingHeader(this->getLayerIdString().c_str())) {
        this->commonGui();
        this->customGui();
    }
    ImGui::PopID();
}

void GifLayer::update() {
    this->calcDelta();
    const float delta = this->getDelta();
    
    if (preloader.getStatus() == GifPreloader::PREPARED) {
        this->gif = preloader.get();
    }
    
    this->updateBegin();
    if (this->gif.use_count() > 0) {
        if ((int)this->frame > this->gif->getFrameCount()) {
            this->frame = 0;
        }
        this->gif->getFrameTexture((int)this->frame)->draw(0, 0);
        
        if (this->playGif) {
            this->frame += delta * (float)gif->getDelay((int)this->frame) / 1000.0f;
        }
    }
    this->updateEnd();
}

void GifLayer::customGui() {
    ImGui::InputText("Filename", this->filename, 256);
    if (ImGui::Button("LOAD")) {
        preloader.preload(ofToDataPath(this->filename));
    }
    if (this->gif.use_count() > 0) {
        if (!this->playGif) {
            ImGui::SameLine();
            if (ImGui::Button("PLAY")) {
                this->play();
            }
        } else {
            ImGui::SameLine();
            if (ImGui::Button("STOP")) {
                this->stop();
            }
        }
    }
}
