#include "layer_container.hpp"
#include "../core/app.hpp"

const int atlas::core::LayerContainer::NUM_LAYERS;

atlas::core::LayerContainer::LayerContainer() {
    for (int i = 0; i < NUM_LAYERS; i++) {
        this->layers[i] = std::make_shared<atlas::layer::Empty>();
    }
}

atlas::core::LayerContainer::~LayerContainer() {
    
}

const std::shared_ptr<atlas::layer::Base>& atlas::core::LayerContainer::getLayer(int index) {
    // TODO: check index range
    return this->layers[index];
}

void atlas::core::LayerContainer::setLayer(int index, int layerType) {
    switch (layerType) {
        case atlas::layer::LAYER_TYPE_EMPTY:
            this->layers[index] = std::make_shared<atlas::layer::Empty>();
            break;
        case atlas::layer::LAYER_TYPE_GIF:
            this->layers[index] = std::make_shared<atlas::layer::Gif>();
            this->layers[index]->setup(index, atlas::core::App::instance().settings);
            break;
        case atlas::layer::LAYER_TYPE_GIFDIRECTORY:
            this->layers[index] = std::make_shared<atlas::layer::GifDirectory>();
            this->layers[index]->setup(index, atlas::core::App::instance().settings);
            break;
        case atlas::layer::LAYER_TYPE_TEXT:
            this->layers[index] = std::make_shared<atlas::layer::Text>();
            this->layers[index]->setup(index, atlas::core::App::instance().settings);
            break;
        case atlas::layer::LAYER_TYPE_IMAGE:
            this->layers[index] = std::make_shared<atlas::layer::Image>();
            this->layers[index]->setup(index, atlas::core::App::instance().settings);
            break;
        case atlas::layer::LAYER_TYPE_IMAGESLIDESHOW:
            this->layers[index] = std::make_shared<atlas::layer::ImageSlideshow>();
            this->layers[index]->setup(index, atlas::core::App::instance().settings);
            break;
        default:
            break;
    }
}

json atlas::core::LayerContainer::saveJson() {
    json j;
    j["layers"] = json::array({});
    
    for (int i = 0; i < NUM_LAYERS; i++) {
        j["layers"].push_back(this->layers[i]->saveJson());
    }
    return j;
}

void atlas::core::LayerContainer::loadJson(const json &j) {
    for (auto& layer : j["layers"]) {
        if (layer.count("layer_type") == 0 || layer.count("props") == 0 || (layer.count("props") > 0 && layer["props"].count("index") == 0)) {
            continue;
        }
        const int index = layer["props"]["index"].get<int>();
        
        this->setLayer(index, layer["layer_type"].get<int>());
        this->layers[index]->loadJson(layer);
    }
}
