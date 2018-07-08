#include "layer_container.hpp"
#include "../layer/empty.hpp"
#include "../layer/gif_directory.hpp"

#include "../core/app.hpp"

const int atlas::core::LayerContainer::NUM_LAYERS;

atlas::core::LayerContainer::LayerContainer() {
    for (int i = 0; i < NUM_LAYERS; i++) {
        this->layers[i] = std::make_shared<atlas::layer::Empty>();
    }
    
    // TODO: Remove after dev
    this->layers[0] = std::make_shared<atlas::layer::GifDirectory>();
    this->layers[0]->setup(atlas::core::App::instance().settings);
    this->layers[1] = std::make_shared<atlas::layer::GifDirectory>();
    this->layers[1]->setup(atlas::core::App::instance().settings);
}

atlas::core::LayerContainer::~LayerContainer() {
    
}

const std::shared_ptr<atlas::layer::Base>& atlas::core::LayerContainer::getLayer(int index) {
    // TODO: check index range
    return this->layers[index];
}

