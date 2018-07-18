#include "gif_directory.hpp"

void atlas::layer::GifDirectory::setup(const int layerIndex, const atlas::core::AppSettings &settings) {
    FboCanvas::setup(layerIndex, settings);
    this->mediaSelector.setMode(atlas::gui::view::DIR_SELECT);
}

void atlas::layer::GifDirectory::update(double delta) {
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
    
    this->fbo->begin();
    ofSetColor(255, 255, 255);
    ofClear(0, 0, 0, 255);
    
    if (this->currentGif.use_count() > 0) {
        if ((int)this->frame > this->currentGif->getFrameCount()) {
            this->currentGif = this->preloadQueue.front();
            this->preloadQueue.pop();
            this->frame = 0;
        }
        
        this->drawTexture(*this->currentGif->getFrameTexture((int)this->frame));
        
        if (this->playGif) {
            this->frame += delta * (float)this->currentGif->getDelay((int)this->frame) / 1000.0f;
        }
        
    }
    
    this->fbo->end();
}

void atlas::layer::GifDirectory::gui() {
    ImGui::InputText("Directory", this->directory, 256);
    if (ImGui::Button("LOAD")) {
        this->load();
    }
    if (this->mediaSelector.draw()) {
        ofLogNotice() << this->mediaSelector.getSelected();
    }
    
    if (this->gifList.size() > 0 && this->currentGif.use_count() > 0) {
        ImGui::Text("Now playing %i/%i", this->gifListIndex + 1 - PRELOAD_QUEUE_SIZE, (int)this->gifList.size());
        
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

void atlas::layer::GifDirectory::play() {
    this->playGif = true;
}

void atlas::layer::GifDirectory::stop() {
    this->playGif = false;
}

void atlas::layer::GifDirectory::load() {
    ofDirectory dir;
    
    dir.open(this->directory);
    dir.allowExt("gif");
    
    const int size = (int)dir.listDir();
    if (size > 0) {
        ofLog(OF_LOG_NOTICE) << "gifDirectory: " << size << " files found in " << this->directory;
        this->gifList.clear();
        for (int i = 0; i < dir.size(); i ++) {
            this->gifList.push_back(dir.getPath(i));
        }
        this->gifListIndex = 0;
    } else {
        ofLog(OF_LOG_NOTICE) << "gifDirectory: no files found or directory doesnt exists: " << this->directory;
    }
}
