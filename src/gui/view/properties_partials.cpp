#include "properties_partials.hpp"
#include "../../core/app.hpp"

void atlas::gui::view::PropertiesPartials::createLayerGui(int index) {
    std::shared_ptr<atlas::layer::Base> layer = atlas::core::App::instance().getLayerContainer()->getLayer(index);
    std::shared_ptr<atlas::core::LayerContainer> container = atlas::core::App::instance().getLayerContainer();
    
    if (layer->getLayerType() == atlas::layer::LAYER_TYPE_EMPTY) {
        ImGui::Text("This layer is empty. To create layer select one of following type.");
        
        if (ImGui::Button("GIF DIRECTORY")) {
            container->setLayer(index, atlas::layer::LAYER_TYPE_GIFDIRECTORY);
        }
        ImGui::Text("Play gifs from selected directory.");
        if (ImGui::Button("GIF")) {
            container->setLayer(index, atlas::layer::LAYER_TYPE_GIF);
        }
        ImGui::Text("Play single gif.");
        if (ImGui::Button("TEXT")) {
            container->setLayer(index, atlas::layer::LAYER_TYPE_TEXT);
        }
        ImGui::Text("Display user defined text using custom truetype font (.ttf only)");
        if (ImGui::Button("IMAGE")) {
            container->setLayer(index, atlas::layer::LAYER_TYPE_IMAGE);
        }
        ImGui::Text("Display image (.jpg or .png)");
        if (ImGui::Button("IMAGE_SLIDESHOW")) {
            container->setLayer(index, atlas::layer::LAYER_TYPE_IMAGESLIDESHOW);
        }
        ImGui::Text("Create slideshow of all images in directory (.jpg or .png)");
    } else {
        if (ImGui::Button("DELETE LAYER")) {
            container->setLayer(index, atlas::layer::LAYER_TYPE_EMPTY);
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
    
    ImGui::Separator();
}
