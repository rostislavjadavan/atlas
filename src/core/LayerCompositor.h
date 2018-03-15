#pragma once

#include "ApplicationSettings.h"
#include "LayerManager.h"
#include "ofMain.h"

class LayerCompositor {
	public:
		LayerCompositor(ApplicationSettings settings);
		~LayerCompositor();

		ofFbo render(std::shared_ptr<LayerManager> manager);

	private:
		ApplicationSettings settings;
		ofFbo fbo;
};