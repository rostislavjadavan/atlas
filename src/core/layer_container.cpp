#include "layer_container.hpp"

const int atlas::core::LayerContainer::NUM_LAYERS;

atlas::core::LayerContainer::LayerContainer() {
    for (int i = 0; i < NUM_LAYERS; i ++) {
        //this->layers[i] == std::make_shared<layer::Base>();
    }
}

atlas::core::LayerContainer::~LayerContainer() {
    
}
