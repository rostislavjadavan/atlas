#include "properties_partials.hpp"
#include "../../core/app.hpp"
#include "../layer/empty.hpp"
#include "../layer/gif_directory.hpp"
#include "../layer/text.hpp"

void atlas::gui::view::PropertiesPartials::createLayerGui(int index) {
    std::shared_ptr<atlas::layer::Base> layer = atlas::core::App::instance().getLayerContainer()->getLayer(index);
    
    if (layer->getLayerType() == atlas::layer::LAYER_TYPE_EMPTY) {
        ImGui::Text("This layer is empty. To create layer select one of following type.");
        
        if (ImGui::Button("GIF DIRECTORY")) {
            atlas::core::App::instance().getLayerContainer()->setLayer(index, std::make_shared<atlas::layer::GifDirectory>());
        }
        ImGui::Text("Play gifs from selected directory.");
        if (ImGui::Button("TEXT")) {
            atlas::core::App::instance().getLayerContainer()->setLayer(index, std::make_shared<atlas::layer::Text>());
        }
        ImGui::Text("Display user defined text using custom truetype font (.ttf only)");
    } else {
        if (ImGui::TreeNode("Delete layer")) {
            ImGui::Text("Do you really want to delete this layer?");
            if (ImGui::Button("YES, DELETE")) {
                atlas::core::App::instance().getLayerContainer()->setLayer(index, std::make_shared<atlas::layer::Empty>());
            }
            ImGui::TreePop();
        }
    }
}

void atlas::gui::view::PropertiesPartials::baseLayerPropsGui(int index) {
    std::shared_ptr<atlas::layer::Base> layer = atlas::core::App::instance().getLayerContainer()->getLayer(index);
    
    ImGui::SliderFloat("opacity", &layer->props.alpha, 0.0f, 1.0f);
    ImGui::Combo("blend mode", &layer->props.blendMode, atlas::core::BlendShaders::IMGUI_COMBO_STRING);
    ImGui::Combo("draw mode", &layer->props.drawMode, atlas::layer::IMGUI_COMBO_LAYER_DRAW_MODES);
    ImGui::InputInt("position x", &layer->props.x);
    ImGui::InputInt("position y", &layer->props.y);
    ImGui::InputInt("width", &layer->props.width);
    ImGui::InputInt("height", &layer->props.height);
    ImGui::Checkbox("disable from output", &layer->props.disabledFromOutput);
    
    ImGui::Separator();
}
