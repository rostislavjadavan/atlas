#include "FboLayer.h"

FboLayer::FboLayer(int width, int height) {
	this->width = width;
    this->height = height;
    this->fbo.allocate(width, height, GL_RGBA);

    this->layerInfo.width = width;
    this->layerInfo.height = height;
    this->layerInfo.posX = 0;
    this->layerInfo.posY = 0;
    this->layerInfo.alpha = 0.5f;
    this->layerInfo.blendMode = OF_BLENDMODE_ADD;
    this->layerInfo.backgroundColor = ofColor(0, 0, 0, 255);

    this->guiBlendMode = 2;
}

FboLayer::~FboLayer() {}

void FboLayer::setup() {
	
}

void FboLayer::displayGui() {
	ImGui::PushID(this->getLayerIdString().c_str());
	if (ImGui::CollapsingHeader(this->getLayerIdString().c_str())) {
		this->commonGui();
		this->customGui();
	}
	ImGui::PopID();
}

void FboLayer::update() {
    this->fbo.begin();
    ofClear(this->layerInfo.backgroundColor);
    this->fbo.end();
}

LayerInfo &FboLayer::getInfo() {
	return this->layerInfo;
}

ofFbo FboLayer::getOutput() {
    return this->fbo;
}

void FboLayer::commonGui() {
	// TODO: working preview
	//ImGui::Image((GLuint*)this->fbo.getTexture().getTextureData().textureID, ImVec2(200, 200));

	if (ImGui::TreeNode("color & blending")) {
		ImGui::SliderFloat("opacity", &this->layerInfo.alpha, 0.0f, 1.0f);
		ImGui::ColorEdit3("background color", (float*)&this->layerInfo.backgroundColor);

		ImGui::Combo("blend mode", &this->guiBlendMode, "DISABLED\0ALPHA\0ADD\0SUBTRACT\0MULTIPLY\0SCREEN\0");
		switch(this->guiBlendMode) {
			case 5:
				this->layerInfo.blendMode = OF_BLENDMODE_SCREEN;
				break;
			case 4:
				this->layerInfo.blendMode = OF_BLENDMODE_MULTIPLY;
				break;
			case 3:
				this->layerInfo.blendMode = OF_BLENDMODE_SUBTRACT;
				break;
			case 2:
				this->layerInfo.blendMode = OF_BLENDMODE_ADD;
				break;
			case 1:
				this->layerInfo.blendMode = OF_BLENDMODE_ALPHA;
				break;
			case 0: 
			default:
				this->layerInfo.blendMode = OF_BLENDMODE_DISABLED;
		}
		ImGui::TreePop();
	}
	if (ImGui::TreeNode("position & size")) {
		ImGui::SliderInt("posX", &this->layerInfo.posX, 0, ofGetWidth());
		ImGui::SliderInt("posY", &this->layerInfo.posY, 0, ofGetHeight());
		ImGui::SliderInt("width", &this->layerInfo.width, 0, ofGetWidth());
		ImGui::SliderInt("height", &this->layerInfo.height, 0, ofGetHeight());
		ImGui::TreePop();
	}
}

void FboLayer::customGui() {

}
