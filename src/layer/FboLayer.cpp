#include "FboLayer.h"

FboLayer::FboLayer(int width, int height) {
	this->width = width;
    this->height = height;
    this->fbo.allocate(width, height, GL_RGBA);

    this->layerInfo.width = width;
    this->layerInfo.height = height;
    this->layerInfo.posX = 0;
    this->layerInfo.posY = 0;
    this->layerInfo.alpha = 1.0f;
    this->layerInfo.blendMode = OF_BLENDMODE_ADD;

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

	if (ImGui::TreeNode("blending & opacity")) {
		ImGui::SliderFloat("opacity", &this->layerInfo.alpha, 0.0f, 1.0f);

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
		ImGui::InputInt("posX", &this->layerInfo.posX);
		ImGui::InputInt("posY", &this->layerInfo.posY);
		ImGui::InputInt("width", &this->layerInfo.width);
		ImGui::InputInt("height", &this->layerInfo.height);
		ImGui::TreePop();
	}
}

void FboLayer::customGui() {

}

void FboLayer::updateBegin() {
    this->fbo.begin();
    ofClear(0, 0, 0, 255);
    
}

void FboLayer::updateEnd() {
    this->fbo.end();
}

void FboLayer::reinit(int width, int height) {
    this->width = width;
    this->height = height;
    this->fbo.allocate(width, height, GL_RGBA);
    
    this->layerInfo.width = width;
    this->layerInfo.height = height;
}
