#include "ofOutputApp.h"
#include "core/app.hpp"

//--------------------------------------------------------------
void ofOutputApp::setup() {
    ofLog(OF_LOG_NOTICE) << "Output window starting...";
}

//--------------------------------------------------------------
void ofOutputApp::update(){
}

//--------------------------------------------------------------
void ofOutputApp::draw(){
    ofSetColor(255, 255, 255);
    atlas::core::App::instance().getLayerCompositor()->getFrame()->draw(0, 0, ofGetWidth(), ofGetHeight());
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
