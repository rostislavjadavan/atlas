#include "VideoLayer.h"

VideoLayer::VideoLayer(int width, int height): FboLayer(width, height) {
    
}

VideoLayer::~VideoLayer() {
    
}

void VideoLayer::load() {
    if (this->video.isLoaded()) {
        this->video.close();
    }
    this->video.load(std::string(this->filename));
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
    if (ImGui::CollapsingHeader(this->getLayerIdString().c_str())) {
        this->commonGui();
        this->customGui();
    }
    ImGui::PopID();
}

void VideoLayer::update() {
    this->updateBegin();
    if (this->video.isLoaded()) {
        this->video.update();
        this->video.draw(0, 0);
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
