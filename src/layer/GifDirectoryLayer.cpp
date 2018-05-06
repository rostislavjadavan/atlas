#include "GifDirectoryLayer.h"

GifDirectoryLayer::GifDirectoryLayer(int width, int height): FboLayer(width, height) {
    this->frame = 0;
    this->gif = 0;
    this->currentGif = new GifDecoder();
    this->nextGif = new GifDecoder();
}

GifDirectoryLayer::~GifDirectoryLayer() {
    delete this->currentGif;
    delete this->nextGif;
}

void GifDirectoryLayer::load() {
    this->gifs.open(this->directory);
    this->gifs.allowExt("gif");
    
    int size = (int)this->gifs.listDir();
    if (size == 0) {
        ofLog(OF_LOG_NOTICE) << "gifDirectory: no files found or directory doesnt exists: " << this->directory;
        this->isLoaded = false;
    } else {
        ofLog(OF_LOG_NOTICE) << "gifDirectory: " << size << " files found in " << this->directory;
        this->isLoaded = true;
        
        if (!this->currentGif->load(ofToDataPath(this->gifs.getPath(0)).c_str())) {
            this->isLoaded = false;
            ofLog(OF_LOG_ERROR) << "gifDirectory: unable to load: " << this->gifs.getPath(0);
        }
    }
}

void GifDirectoryLayer::play() {
    
}

void GifDirectoryLayer::stop() {
    
}

void GifDirectoryLayer::displayGui() {
    ImGui::PushID(this->getLayerIdString().c_str());
    if (ImGui::CollapsingHeader(this->getLayerIdString().c_str())) {
        this->commonGui();
        this->customGui();
    }
    ImGui::PopID();
}

void GifDirectoryLayer::update() {
    this->calcDelta();
    const float delta = this->getDelta();
    
    this->updateBegin();
    if (this->isLoaded) {
        if ((int)this->frame > this->currentGif->getFrameCount()) {
            delete this->currentGif;
            this->currentGif = result.get();
            this->frame = 0;
            this->runPreload = true;
        }
        this->currentGif->getFrameTexture((int)this->frame)->draw(0, 0);
        this->frame += delta * (float)this->currentGif->getDelay((int)this->frame) / 1000.0f;
        
        if (this->runPreload) {
            this->gif++;
            if (this->gif >= this->gifs.size()) {
                this->gif = 0;
            }
            result = std::async(std::launch::async, [](std::string path) {
                GifDecoder *decoder = new GifDecoder();
                decoder->load(ofToDataPath(path).c_str());
                return decoder;
            }, this->gifs.getPath(this->gif));
            this->runPreload = false;
        }
    }
    this->updateEnd();
}

void GifDirectoryLayer::customGui() {
    ImGui::InputText("Directory", this->directory, 256);
    if (ImGui::Button("LOAD")) {
        this->load();
    }
    if (this->isLoaded) {
        ImGui::Text("Loaded files: %i", (int)this->gifs.size());
        ImGui::Text("Now playing %i/%i: %s", this->gif, (int)this->gifs.size(), this->currentGif->getFilename().c_str());
        
        if (ImGui::Button("PLAY")) {
            this->play();
        }
        ImGui::SameLine();
        if (ImGui::Button("STOP")) {
            this->stop();
        }
    }
}
