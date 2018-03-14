#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    FboLayer *pFboLayer1 = new FboLayer(600, 600);
    pFboLayer1->getInfo().posX = 300;
    pFboLayer1->getInfo().posY = 100;

    FboLayer *pFboLayer2 = new FboLayer(400, 400);
    pFboLayer2->getInfo().posX = 100;
    pFboLayer2->getInfo().posY = 300;

    FboLayer *pFboLayer3 = new FboLayer(400, 400);
    pFboLayer3->getInfo().posX = 0;
    pFboLayer3->getInfo().posY = 0;

    this->pLayerManager = std::make_shared<LayerManager>();
    this->pLayerManager->add(pFboLayer1);
    this->pLayerManager->add(pFboLayer2);
    this->pLayerManager->add(pFboLayer3);
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
    ImGui::SetNextWindowPos(ImVec2(10, 10));
    ImGui::SetNextWindowSize(ofVec2f(600, ofGetHeight() - 80), ImGuiSetCond_FirstUseEver);
    ImGui::Begin("Atlas Compositor");
        this->pLayerManager->runDisplayGui();
    ImGui::End();
    gui.end();
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
