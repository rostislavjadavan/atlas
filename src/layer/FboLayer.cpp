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
    this->layerInfo.layerDrawMode = LayerDrawMode::FIT;

    this->guiBlendMode = 2;
    this->guiDrawMode = 2;
}

FboLayer::~FboLayer() {}

void FboLayer::setup() {
	
}

void FboLayer::displayGui() {
	ImGui::PushID(this->getLayerIdString().c_str());
	if (ImGui::CollapsingHeader((this->getName() + " (" + this->getLayerIdString() + ")").c_str())) {
		this->commonGui();
		this->customGui();
	}
	ImGui::PopID();
}

void FboLayer::update() {
    this->updateBegin();
    this->updateEnd();
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
        ImGui::Combo("draw mode", &this->guiDrawMode, "ORIGINAL\0STRETCH\0FIT\0");
        switch(this->guiDrawMode) {
            case 2:
                this->layerInfo.layerDrawMode = LayerDrawMode::FIT;
                break;
            case 1:
                this->layerInfo.layerDrawMode = LayerDrawMode::STRETCH;
                break;
            case 0:
            default:
                this->layerInfo.layerDrawMode = LayerDrawMode::ORIGINAL;
        }
        
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
    this->calcDelta();
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

void FboLayer::drawTexture(const ofTexture &tex) {
    float fx, fy, fw, fh;
    switch(this->layerInfo.layerDrawMode) {
        case LayerDrawMode::FIT: {
            float scale = std::fmin(tex.getHeight()/(float)this->height, tex.getWidth()/(float)this->width);
            fx = (float)this->width/2 - tex.getWidth() / 2 / scale;
            fy = (float)this->height/2 - tex.getHeight() / 2 / scale;
            fw = tex.getWidth() / scale;
            fh = tex.getHeight() / scale;
            break;
        }
        case LayerDrawMode::STRETCH: {
            fx = 0;
            fy = 0;
            fw = this->width;
            fh = this->height;
            break;
        }
        case LayerDrawMode::ORIGINAL:
        default:
            fx = (float)this->width/2 - tex.getWidth() / 2;
            fy = (float)this->height/2 - tex.getHeight() / 2;
            fw = tex.getWidth();
            fh = tex.getHeight();
    }
    tex.draw(fx, fy, fw, fh);
}
