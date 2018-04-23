#pragma once

#include "ofMain.h"
#include "ofxImGui.h"
#include "layer/FboLayer.h"
#include "core/ApplicationSettings.h"
#include "core/LayerManager.h"
#include "core/LayerCompositor.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofxImGui::Gui gui;
	float floatValue;
	ImVec4 backgroundColor;

	ApplicationSettings settings;
	std::shared_ptr<LayerManager> pLayerManager;
	std::shared_ptr<LayerCompositor> pLayerCompositor;
    
    std::string appName = "Atlas Compositor";
};
