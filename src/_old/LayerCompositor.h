#pragma once

#include "ApplicationSettings.h"
#include "LayerManager.h"
#include "ofMain.h"

class LayerCompositor {
	public:
		LayerCompositor(std::shared_ptr<ApplicationSettings> settings);
		~LayerCompositor();

		ofFbo render(std::shared_ptr<LayerManager> manager);

	private:
		std::shared_ptr<ApplicationSettings> pSettings;
		ofFbo fbo;
};
