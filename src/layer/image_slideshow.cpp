#include "image_slideshow.hpp"

void atlas::layer::ImageSlideshow::setup(const int layerIndex,const atlas::core::AppSettings &settings) {
    FboCanvas::setup(layerIndex, settings);
    this->mediaSelector.setMode(atlas::gui::view::DIR_SELECT);
    this->imageTime = 1.0f;
}

void atlas::layer::ImageSlideshow::update(const double delta) {
    if (this->imageList.size() > 0 && this->preloadQueue.size() < PRELOAD_QUEUE_SIZE && this->preloader.getStatus() == atlas::layer::libs::ImagePreloader::WAITING) {
        this->preloader.preload(this->imageList.at(this->imageListIndex));
        
        this->imageListIndex++;
        if (this->imageListIndex >= this->imageList.size()) {
            this->imageListIndex = 0;
        }
    }
    
    if (this->preloader.getStatus() == atlas::layer::libs::ImagePreloader::PREPARED) {
        std::shared_ptr<ofImage> tmpImage = std::make_shared<ofImage>();
        tmpImage->setFromPixels(*this->preloader.get());
        this->preloadQueue.push(tmpImage);
    }
    
    if (this->currentImage.use_count() == 0 && this->preloadQueue.size() > 0) {
        this->currentImage = this->preloadQueue.front();
        this->preloadQueue.pop();
    }
    
    this->fbo->begin();
    ofSetColor(255, 255, 255);
    ofClear(0, 0, 0, 0);
    
    if (this->currentImage.use_count() > 0) {
        if (this->currentImageTime > this->imageTime) {
            if (this->preloadQueue.size() > 0) {
                this->currentImage = this->preloadQueue.front();
                this->preloadQueue.pop();
            }
            this->currentImageTime = 0;
        }
        
        this->drawTexture(this->currentImage->getTexture());
        
        if (this->play) {
            this->currentImageTime += delta / 1000.0f;
        }
    }
    
    this->fbo->end();
}

void atlas::layer::ImageSlideshow::gui() {
    ImGui::Text("%s", this->mediaSelector.getSelected().getFileName().c_str());
    if (this->mediaSelector.draw()) {
        std::queue<std::shared_ptr<ofImage>>().swap(this->preloadQueue);
        this->imageListIndex = 0;
        this->currentImageTime = 0;
        this->imageList.clear();
        this->load();
    }
    
    ImGui::InputFloat("Image duration (sec)", &this->imageTime);
    
    if (this->imageList.size() > 0 && this->currentImage.use_count() > 0) {
        ImGui::Text("Now playing %i/%i", this->imageListIndex + 1 - PRELOAD_QUEUE_SIZE, (int)this->imageList.size());
        
        if (!this->play) {
            if (ImGui::Button("PLAY")) {
                this->play = true;
            }
        } else {
            if (ImGui::Button("STOP")) {
                this->play = false;
            }
        }
    }
    
    ImGui::Separator();
    this->partials.baseLayerPropsGui(props.index);
    this->partials.bpmLayerPropsGui(props.index);
}

void atlas::layer::ImageSlideshow::load() {
    ofDirectory dir;
    
    dir.open(this->mediaSelector.getSelected().getAbsolutePath());
    dir.allowExt("jpg");
    dir.allowExt("png");
    
    const int size = (int)dir.listDir();
    if (size > 0) {
        this->imageList.clear();
        for (int i = 0; i < dir.size(); i ++) {
            this->imageList.push_back(dir.getPath(i));
        }
        this->imageListIndex = 0;
    }
}
