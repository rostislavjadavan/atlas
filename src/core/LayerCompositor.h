#pragma once

#include "LayerManager.h"
#include "ofMain.h"

class LayerCompositor {
	public:
		LayerCompositor(int width, int height);
		~LayerCompositor();
		ofFbo render(std::shared_ptr<LayerManager> manager);

	private:
		int width, height;
		ofFbo fbo;
};