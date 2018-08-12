#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofLog(OF_LOG_NOTICE) << "[ofApp] App and Gui setup";
    
    atlas::core::App::instance().setup();
    atlas::gui::Gui::instance().setup();
    
    ofLog(OF_LOG_NOTICE) << "[ofApp] Working directory: " <<  ofFilePath::getCurrentWorkingDirectory();
    ofLog(OF_LOG_NOTICE) << "[ofApp] Data directory: " <<  ofToDataPath(".");
}

//--------------------------------------------------------------
void ofApp::update(){
    atlas::core::App::instance().update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    atlas::gui::Gui::instance().draw();
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
//--------------------------------------------------------------
void ofApp::audioReceived(float* input, int bufferSize, int nChannels) {
    atlas::core::App::instance().getBeatDetector()->audioReceived(input, bufferSize, nChannels);
}
