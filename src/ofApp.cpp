#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    atlas::core::App::instance().setup();
    atlas::gui::Gui::instance().setup();
    
    /*ofLog(OF_LOG_NOTICE) << this->appName << " starting...";
    ofLog(OF_LOG_NOTICE) << "workdir: " <<  ofFilePath::getCurrentWorkingDirectory();
    
    ofSetWindowTitle(this->appName);
    
    outputWindow.init();
    
    Application::Instance().pSettings = std::make_shared<ApplicationSettings>();
    Application::Instance().pSettings->compositorWidth = 800;
    Application::Instance().pSettings->compositorHeight = 600;

    Application::Instance().pLayerManager = std::make_shared<LayerManager>(Application::Instance().pSettings);
    Application::Instance().pLayerCompositor = std::make_shared<LayerCompositor>(Application::Instance().pSettings);
     */
    
    /*std::shared_ptr<ParticleSystemLayer> pp = std::make_shared<ParticleSystemLayer>(Application::Instance().pSettings->compositorWidth, Application::Instance().pSettings->compositorHeight);
    pp->create(1000, ofVec2f(400, 300), 30);
    Application::Instance().pLayerManager->add(pp);*/
    
    /*
    gui.setup();
    
    */
}

//--------------------------------------------------------------
void ofApp::update(){
    //Application::Instance().pLayerManager->layersUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(100);
    
    atlas::gui::Gui::instance().draw();
    
    /*
    const int widthHalf = ofGetWidth() / 2;
    const int heightHalf = ofGetHeight() / 2;
    const int previewHeight = widthHalf * Application::Instance().pSettings->getHeightToWidthRatio();
    
    ofClear(100);
    Application::Instance().pLayerCompositor->render(Application::Instance().pLayerManager).draw(widthHalf, 0, widthHalf, previewHeight);
    
	gui.begin();
    
    ofSetColor(0, 0, 0);
    float sizex = Application::Instance().pSettings->compositorWidth / 8;
    float sizey = Application::Instance().pSettings->compositorHeight / 8;
    for (int y = 0; y < 4; y ++) {
        for (int x = 0; x < 4; x ++) {
            ofDrawRectangle(x * sizex, y * sizey, sizex - 1, sizey - 1);
        }
    }
    ofSetColor(255, 255, 255);
    
    ImGui::SetNextWindowPos(ImVec2(0, ofGetHeight()/2));
    ImGui::SetNextWindowSize(ofVec2f(widthHalf - 1, ofGetHeight()/2));
    ImGui::Begin("Atlas Compositor", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                 ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
        Application::Instance().pLayerManager->displayGui();
        this->outputWindow.displayGui();
    ImGui::End();
    gui.end();
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
