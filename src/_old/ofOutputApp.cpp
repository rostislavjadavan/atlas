#include "ofOutputApp.h"

//--------------------------------------------------------------
void ofOutputApp::setup() {
    ofLog(OF_LOG_NOTICE) << "Output window starting...";
    
}

//--------------------------------------------------------------
void ofOutputApp::update(){
    Application::Instance().pLayerManager->layersUpdate();
}

//--------------------------------------------------------------
void ofOutputApp::draw(){
    Application::Instance().pLayerCompositor->render(Application::Instance().pLayerManager).draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofOutputApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofOutputApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofOutputApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofOutputApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofOutputApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofOutputApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofOutputApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofOutputApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofOutputApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofOutputApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofOutputApp::dragEvent(ofDragInfo dragInfo){
    
}
