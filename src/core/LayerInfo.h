#pragma once

#include "ofMain.h"
#include "ofxImGui.h"

struct LayerInfo {
	int posX, posY;
	int width, height;
	float alpha;
	/**
		Blend modes

		OF_BLENDMODE_DISABLED
		OF_BLENDMODE_ALPHA
		OF_BLENDMODE_ADD
		OF_BLENDMODE_SUBTRACT
		OF_BLENDMODE_MULTIPLY
		OF_BLENDMODE_SCREEN
	*/
	ofBlendMode blendMode;
	ImVec4 backgroundColor;
};