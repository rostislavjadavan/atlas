#include "GifDirectoryLayer.h"

GifDirectoryLayer::GifDirectoryLayer(int width, int height): FboLayer(width, height) {
    this->frame = 0;
    this->gifListIndex = 0;
}

GifDirectoryLayer::~GifDirectoryLayer() {
    
}

void GifDirectoryLayer::load() {
    ofDirectory dir;
    
    dir.open(this->directory);
    dir.allowExt("gif");
    
    const int size = (int)dir.listDir();
    if (size > 0) {
        ofLog(OF_LOG_NOTICE) << "gifDirectory: " << size << " files found in " << this->directory;
        for (int i = 0; i < dir.size(); i ++) {
            this->gifList.push_back(dir.getPath(i));
        }
        this->gifListIndex = 0;
    } else {
        ofLog(OF_LOG_NOTICE) << "gifDirectory: no files found or directory doesnt exists: " << this->directory;
    }
}

void GifDirectoryLayer::play() {
    this->playGif = true;
}

void GifDirectoryLayer::stop() {
    this->playGif = false;
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
    
    if (this->gifList.size() > 0 && this->preloadQueue.size() < PRELOAD_QUEUE_SIZE && this->preloader.getStatus() == GifPreloader::WAITING) {
        this->preloader.preload(this->gifList.at(this->gifListIndex));
        
        this->gifListIndex++;
        if (this->gifListIndex >= this->gifList.size()) {
            this->gifListIndex = 0;
        }
    }
    
    if (this->preloader.getStatus() == GifPreloader::PREPARED) {
        this->preloadQueue.push(this->preloader.get());
    }
    
    if (this->currentGif.use_count() == 0 && this->preloadQueue.size() > 0) {
        this->currentGif = this->preloadQueue.front();
        this->preloadQueue.pop();
    }
    
    this->updateBegin();
    if (this->currentGif.use_count() > 0) {
        if ((int)this->frame > this->currentGif->getFrameCount()) {
            this->currentGif = this->preloadQueue.front();
            this->preloadQueue.pop();
            this->frame = 0;
        }
        
        this->currentGif->getFrameTexture((int)this->frame)->draw(0, 0);
        
        if (this->playGif) {
            this->frame += delta * (float)this->currentGif->getDelay((int)this->frame) / 1000.0f;
        }
        
    }
    
    this->updateEnd();
}

void GifDirectoryLayer::customGui() {
    ImGui::InputText("Directory", this->directory, 256);
    if (ImGui::Button("LOAD")) {
        this->load();
    }
    if (this->gifList.size() > 0 && this->currentGif.use_count() > 0) {
        ImGui::Text("Loaded files: %i", (int)this->gifList.size());
        ImGui::Text("Now playing %i/%i: %s", this->gifListIndex, (int)this->gifList.size(), this->currentGif->getFilename().c_str());
        ImGui::Text("preloadQueue size %i", (int)this->preloadQueue.size());
        
        if (!this->playGif) {
            if (ImGui::Button("PLAY")) {
                this->play();
            }
        } else {
            if (ImGui::Button("STOP")) {
                this->stop();
            }
        }
    }
}
