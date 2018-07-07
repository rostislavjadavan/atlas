#include "layer_container.hpp"
#include "../layer/empty.hpp"

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

