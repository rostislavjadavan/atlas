#include "properties_partials.hpp"
#include "../../core/app.hpp"
#include "../layer/empty.hpp"
#include "../layer/gif_directory.hpp"

void atlas::gui::view::PropertiesPartials::createLayerGui(int index, bool createEmptyLayer) {
    ImGui::Text("set layer type");
    if (ImGui::Button("GIF DIRECTORY")) {
        atlas::core::App::instance().getLayerContainer()->setLayer(index, std::make_shared<atlas::layer::GifDirectory>());
    }
    ImGui::SameLine();
    if (ImGui::Button("GIF")) {
        
    }
    ImGui::SameLine();
    if (ImGui::Button("TEXT")) {
        
    }
    ImGui::SameLine();
    if (ImGui::Button("TIMETABLE")) {
        
    }
    ImGui::SameLine();
    if (ImGui::Button("IMAGE")) {
        
    }
    ImGui::SameLine();
    if (ImGui::Button("IMAGE SLIDESHOW")) {
        
    }
    ImGui::SameLine();
    if (ImGui::Button("3D MODEL")) {
        
    }
    ImGui::SameLine();
    if (ImGui::Button("LUA SCRIPT")) {
        
    }
    ImGui::SameLine();
    if (ImGui::Button("EMPTY")) {
        atlas::core::App::instance().getLayerContainer()->setLayer(index, std::make_shared<atlas::layer::Empty>());
    }
}
