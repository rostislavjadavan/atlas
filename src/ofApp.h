#pragma once

#include "ofMain.h"
#include "ofxImGui.h"
#include "core/ApplicationSettings.h"
#include "core/LayerManager.h"
#include "core/LayerCompositor.h"
#include "output/OutputWindow.h"

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

	ApplicationSettings settings;
	std::shared_ptr<LayerManager> pLayerManager;
	std::shared_ptr<LayerCompositor> pLayerCompositor;
    
    OutputWindow outputWindow;
    
    std::string appName = "Atlas Compositor";
};
