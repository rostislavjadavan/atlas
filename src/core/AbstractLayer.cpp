#include "AbstractLayer.h"

int AbstractLayer::layerCounter = 0;

AbstractLayer::AbstractLayer() {
	this->layerId = layerCounter;
    layerCounter++;
}

int AbstractLayer::getLayerId() {
	return this->layerId;
}

std::string AbstractLayer::getLayerIdString() {
	char s[100];
    sprintf(s, "layer%d", this->layerId);
    return std::string(s);
}
