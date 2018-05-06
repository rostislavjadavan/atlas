#include "GifLayer.h"

GifLayer::GifLayer(int width, int height): FboLayer(width, height) {
    frame = 0;
}

GifLayer::~GifLayer() {
    
}

void GifLayer::load() {
    this->isLoaded = this->gif.load(ofToDataPath(this->filename).c_str());
    if (this->isLoaded) {
        ofLog(OF_LOG_NOTICE) << "gif loaded: " << this->filename << ", width: " << this->gif.getWidth() << ", height: " << this->gif.getHeight() << ", frames: " << this->gif.getFrameCount();
        this->reinit(this->gif.getWidth(), this->gif.getHeight());
    }
}

void GifLayer::play() {
    
}

void GifLayer::stop() {
    
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
    
    this->updateBegin();
    if (this->isLoaded) {
        if ((int)this->frame > this->gif.getFrameCount()) {
            this->frame = 0;
        }
        this->gif.getFrameTexture((int)this->frame)->draw(0, 0);
        
        this->frame += delta * (float)gif.getDelay((int)this->frame) / 1000.0f;
    }
    this->updateEnd();
}

void GifLayer::customGui() {
    ImGui::InputText("Filename", this->filename, 256);
    if (ImGui::Button("LOAD")) {
        this->load();
    }
    if (this->isLoaded) {
        if (ImGui::Button("PLAY")) {
            this->play();
        }
        ImGui::SameLine();
        if (ImGui::Button("STOP")) {
            this->stop();
        }
    }
}
