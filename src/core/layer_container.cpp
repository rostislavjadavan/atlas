#include "layer_container.hpp"
#include "../layer/empty.hpp"
#include "../layer/gif_directory.hpp"

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

void atlas::core::LayerContainer::setLayer(int index, std::shared_ptr<atlas::layer::Base> layer) {
    // TODO: check index range
    this->layers[index] = layer;
    this->layers[index]->setup(index, atlas::core::App::instance().settings);
}

