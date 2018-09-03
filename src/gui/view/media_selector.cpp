#include "media_selector.hpp"
#include "../gui.hpp"

atlas::gui::view::MediaSelector::MediaSelector() {
    this->setPath(atlas::gui::Gui::instance().settings.lastMediaSelectorDirectory);
    this->mode = FILE_SELECT;
}

bool atlas::gui::view::MediaSelector::draw() {
    const float width = ofGetWidth() / 3;
    return this->draw(ofRectangle(width, 0, ofGetWidth() - width, ofGetHeight()));
}

bool atlas::gui::view::MediaSelector::draw(ofRectangle rect) {
    if (this->display) {
        atlas::gui::Gui::instance().disableSelections();
        
        if (ImGui::Button("CANCEL")) {
            this->display = false;
        }
        
        ImGui::SetNextWindowPos(ImVec2(rect.x, rect.y));
        ImGui::SetNextWindowSize(ofVec2f(rect.width, rect.height));
        ImGui::Begin("Select media", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                     ImGuiWindowFlags_NoCollapse);
        
        this->drawDirectoryInput();
        if (this->drawList()) {
            this->display = false;
            ImGui::End();
            return true;
        }
        
        if (ImGui::Button("BACK")) {
            this->goDirUp();
        }
        ImGui::SameLine();
        if (ImGui::Button("CANCEL")) {
            this->display = false;
        }
        ImGui::End();
    } else {
        atlas::gui::Gui::instance().enableSelections();
        std::string label = (this->mode == DIR_SELECT) ? "SELECT DIRECTORY" : "SELECT FILE";
        if (ImGui::Button(label.c_str())) {
            this->display = true;
        }
    }
    return false;
}

void atlas::gui::view::MediaSelector::drawDirectoryInput() {
    if (ImGui::InputText("", this->pathInput, 256)) {
        this->setPath(std::string(this->pathInput));
    }
    ImGui::SameLine();
    if (ImGui::Button("UP")) {
        this->goDirUp();
    }
}

bool atlas::gui::view::MediaSelector::drawList() {
    if (this->mode == FILE_SELECT) {
        for (int i = 0; i < this->fileList.size(); i ++) {
            const ofFile file = this->fileList.at(i);
            if (file.isDirectory()) {
                if (ImGui::Selectable(file.getFileName().c_str())) {
                    this->setPath(file.getAbsolutePath());
                }
            } else {
                if (ImGui::Selectable(file.getFileName().c_str())) {
                    this->selectedMedia = file;
                    return true;
                }
            }
        }
    }
    if (this->mode == DIR_SELECT) {
        ImGui::Columns(2);
        for (int i = 0; i < this->fileList.size(); i ++) {
            const ofFile file = this->fileList.at(i);
            if (file.isDirectory()) {
                if (ImGui::Selectable(file.getFileName().c_str())) {
                    this->setPath(file.getAbsolutePath());
                }
            }
        }
        ImGui::NextColumn();
        for (int i = 0; i < this->fileList.size(); i ++) {
            const ofFile file = this->fileList.at(i);
            if (file.isDirectory()) {
                if (ImGui::Selectable(std::string("SELECT " + file.getFileName()).c_str())) {
                    const ofFile file = this->fileList.at(i);
                    if (file.isDirectory()) {
                        this->selectedMedia = file;
                        ImGui::Columns(1);
                        return true;
                    }
                }
            }
        }
        ImGui::Columns(1);
    }
    return false;
}

bool atlas::gui::view::MediaSelector::setPath(std::string path) {
    this->dir.open(path);
    if (!this->dir.exists()) {
        ofLogError() << "[MediaSelector] Directory does not exists :" << path;
        this->dir.open(this->currentPath);
        return false;
    }
    
    this->currentPath = path;
    atlas::gui::Gui::instance().settings.lastMediaSelectorDirectory = path;
    this->dir.open(path);
    strcpy(this->pathInput, path.c_str());
    
    const int size = (int)this->dir.listDir();
    this->dir.sort();
    
    this->fileList.clear();
    for (int i = 0; i < this->dir.size(); i ++) {
        const ofFile item = this->dir.getFile(i);
        if (item.isFile()) {
            if (this->allowExtList.size() > 0) {
                for (int i = 0; i < this->allowExtList.size(); i++) {
                    if (item.getExtension() == this->allowExtList.at(i)) {
                        fileList.push_back(item);
                    }
                }
            } else {
                fileList.push_back(item);
            }
        } else {
            fileList.push_back(item);
        }
    }
    return true;
}

const ofFile & atlas::gui::view::MediaSelector::getSelected() {
    return this->selectedMedia;
}

bool atlas::gui::view::MediaSelector::setSelected(std::string path) {
    // TODO: check if file exists
    this->selectedMedia.open(path);
    return true;
}

void atlas::gui::view::MediaSelector::setMode(MediaSelectorMode mode) {
    this->mode = mode;
}

void atlas::gui::view::MediaSelector::allowExt(std::string ext) {
    this->allowExtList.push_back(ext);
    this->setPath(this->currentPath);
}

void atlas::gui::view::MediaSelector::goDirUp() {
    int found = this->currentPath.find_last_of("/\\");
    this->setPath(this->currentPath.substr(0, found));
}
