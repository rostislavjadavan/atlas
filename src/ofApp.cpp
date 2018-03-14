#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

    //std::shared_ptr<AbstractLayer> pFboLayer = std::make_shared<FboLayer>(800, 600);
    //pFboLayer->update();
    FboLayer *pFboLayer = new FboLayer(800, 600);

    this->layerManager.add(pFboLayer);
    this->layerManager.runSetup();
}

//--------------------------------------------------------------
void ofApp::update(){
    this->layerManager.runUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < this->layerManager.count(); i++) {
        this->layerManager.get(i)->getOutput().draw(0, 0);
    }

	gui.begin();

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
