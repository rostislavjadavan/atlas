#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofLog(OF_LOG_NOTICE) << this->appName << " starting...";
    ofLog(OF_LOG_NOTICE) << "workdir: " <<  ofFilePath::getCurrentWorkingDirectory();
    
    ofSetWindowTitle(this->appName);
    
    outputWindow.init();
    
    Application::Instance().pSettings = std::make_shared<ApplicationSettings>();
    Application::Instance().pSettings->compositorWidth = 800;
    Application::Instance().pSettings->compositorHeight = 600;

    Application::Instance().pLayerManager = std::make_shared<LayerManager>(Application::Instance().pSettings);
    Application::Instance().pLayerCompositor = std::make_shared<LayerCompositor>(Application::Instance().pSettings);
}

//--------------------------------------------------------------
void ofApp::update(){
    Application::Instance().pLayerManager->layersUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    const int widthHalf = ofGetWidth() / 2;
    const int heightHalf = ofGetHeight() / 2;
    const int previewHeight = widthHalf * Application::Instance().pSettings->getHeightToWidthRatio();
    
    ofClear(100);
    Application::Instance().pLayerCompositor->render(Application::Instance().pLayerManager).draw(widthHalf, 0, widthHalf, previewHeight);
    
	gui.begin();
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ofVec2f(widthHalf - 1, ofGetHeight()));
    ImGui::Begin("Atlas Compositor", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoCollapse);
        Application::Instance().pLayerManager->displayGui();
        this->outputWindow.displayGui();
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
