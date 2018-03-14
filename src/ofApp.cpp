#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    FboLayer *pFboLayer1 = new FboLayer(800, 600);
    pFboLayer1->getInfo().posX = 300;
    pFboLayer1->getInfo().posY = 100;

    FboLayer *pFboLayer2 = new FboLayer(400, 400);
    pFboLayer2->getInfo().posX = 100;
    pFboLayer2->getInfo().posY = 300;

    this->pLayerManager = std::make_shared<LayerManager>();
    this->pLayerManager->add(pFboLayer1);
    this->pLayerManager->add(pFboLayer2);
    this->pLayerManager->runSetup();

    this->pLayerCompositor = std::make_shared<LayerCompositor>(800, 600);
}

//--------------------------------------------------------------
void ofApp::update(){
    this->pLayerManager->runUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    this->pLayerCompositor->render(this->pLayerManager).draw(0, 0, ofGetWidth(), ofGetHeight());

	gui.begin();
    this->pLayerManager->runDisplayGui();
    gui.end();

/*
	//ImGui::SetNextWindowSize(ofVec2f(10,100), ImGuiSetCond_FirstUseEver);
	ImGui::Begin("Window1");
	ImGui::Text("Hello, world!");
        ImGui::SliderFloat("Float", &floatValue, 0.0f, 1.0f);
        
        //this will change the app background color
	ImGui::ColorEdit3("Background Color", (float*)&backgroundColor);
        if(ImGui::Button("Test Window"))
        {
            
        }
        
        if (ImGui::Button("Another Window"))
        {
            
        }

	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::End();
	
	//ImGui::SetNextWindowSize(ofVec2f(300,100), ImGuiSetCond_FirstUseEver);
        ImGui::Begin("Another Window");
        ImGui::Text("Hello");
	ImGui::End();
*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
