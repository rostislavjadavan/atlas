#pragma once

#include "ApplicationSettings.h"
#include "AbstractLayer.h"
#include "layer/Layers.h"
#include <vector>

class LayerManager {
	public:
		LayerManager(std::shared_ptr<ApplicationSettings> settings);
		~LayerManager();

		void add(std::shared_ptr<AbstractLayer> layer);
		void add(AbstractLayer *layer);
		int count();
		std::shared_ptr<AbstractLayer> get(int i);
		
		void layersSetup();
		void layersUpdate();

		void displayGui();

	protected:
		std::shared_ptr<ApplicationSettings> pSettings;
		std::vector<std::shared_ptr<AbstractLayer>> layerList;

		void createGui();
		void moveGui();
		void deleteGui();
};
