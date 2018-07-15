#include "properties.hpp"
#include "../../core/app.hpp"

void atlas::gui::view::Properties::draw(ofRectangle rect, int selectedLayer) {
    ImGui::SetNextWindowPos(ImVec2(rect.x, rect.y));
    ImGui::SetNextWindowSize(ofVec2f(rect.width, rect.height));
    ImGui::Begin("Properties", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
    
    const std::shared_ptr<atlas::core::LayerContainer> container = atlas::core::App::instance().getLayerContainer();
    const std::shared_ptr<atlas::layer::Base> layer = container->getLayer(selectedLayer);
    ImGui::LabelText("", "Layer %i", selectedLayer);
    ImGui::Separator();
    
    layer->gui();

    this->propertiesPartialsView.createLayerGui(selectedLayer);
    
    ImGui::End();
}
