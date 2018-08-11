#include "properties_partials.hpp"
#include "../../core/app.hpp"
#include "../layer/empty.hpp"
#include "../layer/gif_directory.hpp"
#include "../layer/gif.hpp"
#include "../layer/text.hpp"
#include "../layer/image.hpp"

void atlas::gui::view::PropertiesPartials::createLayerGui(int index) {
    std::shared_ptr<atlas::layer::Base> layer = atlas::core::App::instance().getLayerContainer()->getLayer(index);
    
    if (layer->getLayerType() == atlas::layer::LAYER_TYPE_EMPTY) {
        ImGui::Text("This layer is empty. To create layer select one of following type.");
        
        if (ImGui::Button("GIF DIRECTORY")) {
            atlas::core::App::instance().getLayerContainer()->setLayer(index, std::make_shared<atlas::layer::GifDirectory>());
        }
        ImGui::Text("Play gifs from selected directory.");
        if (ImGui::Button("GIF")) {
            atlas::core::App::instance().getLayerContainer()->setLayer(index, std::make_shared<atlas::layer::Gif>());
        }
        ImGui::Text("Play single gif.");
        if (ImGui::Button("TEXT")) {
            atlas::core::App::instance().getLayerContainer()->setLayer(index, std::make_shared<atlas::layer::Text>());
        }
        ImGui::Text("Display user defined text using custom truetype font (.ttf only)");
        if (ImGui::Button("IMAGE")) {
            atlas::core::App::instance().getLayerContainer()->setLayer(index, std::make_shared<atlas::layer::Image>());
        }
        ImGui::Text("Display image (.jpg or .png)");
    } else {
        if (ImGui::Button("DELETE LAYER")) {
            atlas::core::App::instance().getLayerContainer()->setLayer(index, std::make_shared<atlas::layer::Empty>());
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

void atlas::gui::view::PropertiesPartials::bpmLayerPropsGui(int index) {
    std::shared_ptr<atlas::layer::Base> layer = atlas::core::App::instance().getLayerContainer()->getLayer(index);
    
    ImGui::Checkbox("bpm alpha", &layer->props.bpmAlpha.enabled);
    ImGui::Combo("bpm alpha modify by", &layer->props.bpmAlpha.modifiedBy, atlas::layer::IMGUI_COMBO_BPM_MOFIFY_BY_LIST);
    ImGui::SliderFloat("bpm alpha scale", &layer->props.bpmAlpha.scale, 0.0f, 1.0f);
    
    ImGui::Checkbox("bpm size", &layer->props.bpmScale.enabled);
    ImGui::Combo("bpm size modify by", &layer->props.bpmScale.modifiedBy, atlas::layer::IMGUI_COMBO_BPM_MOFIFY_BY_LIST);
    ImGui::SliderFloat("bpm size scale", &layer->props.bpmScale.scale, 0.0f, 1000.0f);
}
