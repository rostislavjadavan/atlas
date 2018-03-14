
#include "LayerManager.h"

void LayerManager::add(std::shared_ptr<AbstractLayer> layer) {
	this->layerList.push_back(layer);
}

void LayerManager::add(AbstractLayer *layer) {
	this->layerList.push_back(std::shared_ptr<AbstractLayer>(layer));
}

int LayerManager::count() {
	return this->layerList.size();
}

std::shared_ptr<AbstractLayer> LayerManager::get(int i) {
	return this->layerList.at(i);
}

void LayerManager::runSetup() {
	std::vector<std::shared_ptr<AbstractLayer>>::iterator iter, end;
	for(iter = this->layerList.begin(), end = this->layerList.end(); iter != end; ++iter) {
		(*iter)->setup();
	}
}

void LayerManager::runDisplayGui() {
std::vector<std::shared_ptr<AbstractLayer>>::iterator iter, end;
	for(iter = this->layerList.begin(), end = this->layerList.end(); iter != end; ++iter) {
		(*iter)->displayGui();
	}
}

void LayerManager::runUpdate() {
std::vector<std::shared_ptr<AbstractLayer>>::iterator iter, end;
	for(iter = this->layerList.begin(), end = this->layerList.end(); iter != end; ++iter) {
		(*iter)->update();
	}
}

