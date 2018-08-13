#include "system.hpp"
#include "../../core/app.hpp"

void atlas::gui::view::System::draw(ofRectangle rect) {
    ImGui::SetNextWindowPos(ImVec2(rect.x, rect.y));
    ImGui::SetNextWindowSize(ofVec2f(rect.width, rect.height));
    ImGui::Begin("System properties", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoCollapse);
    
    std::stringstream strm;
    strm << "fps: " << ofGetFrameRate();
    
    if (ImGui::TreeNode("Performance Information")) {
        ImGui::Text("%s", strm.str().c_str());
        ImGui::TreePop();
    }
    
    if (ImGui::TreeNode("Output Window")) {
        atlas::core::App::instance().getOutputWindow()->gui();
        ImGui::TreePop();
    }
    
    if (ImGui::TreeNode("Load/Save")) {
        ImGui::InputText("name", this->savename, 1024);
        if (ImGui::Button("SAVE")) {
            ofLogNotice() << atlas::core::App::instance().saveWorkspace(this->savename);
        }
        ImGui::Separator();
        for (std::string name: atlas::core::App::instance().listSavedWorkspaces()) {
            if (ImGui::Button(std::string("load " + name).c_str())) {
                atlas::core::App::instance().loadWorkspace(name);
            }
        }
        ImGui::TreePop();
    }
    
    
    ImGui::End();
}
