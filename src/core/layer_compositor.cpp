#include "layer_compositor.hpp"

atlas::core::LayerCompositor::LayerCompositor(std::shared_ptr<LayerContainer> container) {
    this->container = container;
}
