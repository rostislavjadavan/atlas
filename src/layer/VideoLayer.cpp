#include "VideoLayer.h"

VideoLayer::VideoLayer(int width, int height): FboLayer(width, height) {
    
}

VideoLayer::~VideoLayer() {
    
}

void VideoLayer::load() {
    if (this->video.isLoaded()) {
        this->video.close();
    }
    this->video.loadAsync(std::string(this->filename));
    this->video.setVolume(0.0f);
}

void VideoLayer::play() {
    if (this->video.isLoaded()) {
        this->video.play();
    }
}

void VideoLayer::stop() {
    if (this->video.isLoaded()) {
        this->video.stop();
    }
}

void VideoLayer::displayGui() {
    ImGui::PushID(this->getLayerIdString().c_str());
    if (ImGui::CollapsingHeader((this->getName() + " (" + this->getLayerIdString() + ")").c_str())) {
        this->commonGui();
        this->customGui();
    }
    ImGui::PopID();
}

void VideoLayer::update() {
    this->updateBegin();
    if (this->video.isLoaded()) {
        this->video.update();
        if (this->video.isPlaying()) {
            this->drawTexture(this->video.getTexture());
        }
    }
    this->updateEnd();
}

void VideoLayer::customGui() {
    ImGui::InputText("Filename", this->filename, 256);
    if (ImGui::Button("LOAD")) {
        this->load();
    }
    if (video.isLoaded()) {
        if (ImGui::Button("PLAY")) {
            this->play();
        }
        ImGui::SameLine();
        if (ImGui::Button("STOP")) {
            this->stop();
        }
    }
}
