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
    
    
    ImGui::End();
}
