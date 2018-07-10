#include "empty.hpp"
#include "../gui/view/properties_partials.hpp"
#include "../libs/of.hpp"

void atlas::layer::Empty::setup(const int layerIndex, const atlas::core::AppSettings &settings) {
    this->layerIndex = layerIndex;
}

void atlas::layer::Empty::gui() {
    //gui::view::PropertiesPartials pp;
    //pp.createLayer(layerIndex, false);
}
