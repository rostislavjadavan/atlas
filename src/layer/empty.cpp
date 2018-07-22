#include "empty.hpp"
#include "../gui/view/properties_partials.hpp"
#include "../libs/of.hpp"

void atlas::layer::Empty::setup(const int layerIndex, const atlas::core::AppSettings &settings) {
    this->props.init(layerIndex, settings.compositorOutputWidth, settings.compositorOutputHeight);
}

void atlas::layer::Empty::gui() {
}
