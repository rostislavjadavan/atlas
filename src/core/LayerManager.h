#pragma once

#include "AbstractLayer.h"
#include <vector>

class LayerManager {
	public:
		void add(std::shared_ptr<AbstractLayer> layer);
		void add(AbstractLayer *layer);
		int count();
		std::shared_ptr<AbstractLayer> get(int i);
		void runSetup();
		void runDisplayGui();
		void runUpdate();

	private:
		std::vector<std::shared_ptr<AbstractLayer>> layerList;
};