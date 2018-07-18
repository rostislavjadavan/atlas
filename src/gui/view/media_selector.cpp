#include "media_selector.hpp"
#include "../gui.hpp"

atlas::gui::view::MediaSelector::MediaSelector() {
    this->setPath(ofFilePath::getUserHomeDir());
    this->mode = FILE_SELECT;
}

bool atlas::gui::view::MediaSelector::draw() {
    const float x = ofGetWidth() / 10;
    const float y = ofGetHeight() / 10;
    this->draw(ofRectangle(x, y, ofGetWidth() - x * 2, ofGetHeight() - y * 2));
}

bool atlas::gui::view::MediaSelector::draw(ofRectangle rect) {
    if (this->display) {
        atlas::gui::Gui::instance().disableSelections();
        
        ImGui::SetNextWindowPos(ImVec2(rect.x, rect.y));
        ImGui::SetNextWindowSize(ofVec2f(rect.width, rect.height));
        ImGui::Begin("Select media", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                     ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_ShowBorders);
        
        this->drawDirectoryInput();
        if (this->drawList()) {
            this->display = false;
            ImGui::End();
            return true;
        }
        
        if (ImGui::Button("Cancel")) {
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
                    this->selectedMedia = file.getAbsolutePath();
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
                if (ImGui::Selectable("Select")) {
                    const ofFile file = this->fileList.at(i);
                    if (file.isDirectory()) {
                        this->selectedMedia = file.getAbsolutePath();
                        return true;
                    }
                }
            }
        }
        ImGui::Columns(1);
    }
}

bool atlas::gui::view::MediaSelector::setPath(std::string path) {
    this->dir.open(path);
    if (!this->dir.exists()) {
        ofLogError() << "[MediaSelector] Directory does not exists :" << path;
        this->dir.open(this->currentPath);
        return false;
    }
    
    this->currentPath = path;
    this->dir.open(path);
    strcpy(this->pathInput, path.c_str());
    
    const int size = (int)this->dir.listDir();
    this->dir.sort();
    
    this->fileList.clear();
    for (int i = 0; i < this->dir.size(); i ++) {
        fileList.push_back(dir.getFile(i));
    }
    return true;
}

void atlas::gui::view::MediaSelector::goDirUp() {
    int found = this->currentPath.find_last_of("/\\");
    this->setPath(this->currentPath.substr(0, found));
}
