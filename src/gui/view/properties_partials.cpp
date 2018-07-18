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
