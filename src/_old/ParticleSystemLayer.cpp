#include "ParticleSystemLayer.h"

ParticleSystemLayer::ParticleSystemLayer(int width, int height) : FboLayer(width, height) {
    this->guiNumOfParticles = 1000;
    this->guiPosX = this->width / 2;
    this->guiPosY = this->height / 2;
    this->guiLifeMin = 1.0;
    this->guiLifeMax = 50.0;
    this->guiSizeMin = 1.0f;
    this->guiSizeMax = 25.0f;
    this->guiSpeedMin = 1.0f;
    this->guiSpeedMax = 25.0f;
    this->guiSpread = 10.0f;
}

ParticleSystemLayer::~ParticleSystemLayer() {
    
}

void ParticleSystemLayer::create() {
    for (int i = 0; i < this->guiNumOfParticles; i ++) {
        this->generateParticle();
    }
}

void ParticleSystemLayer::update() {
    const float delta = this->getDelta();
    this->updateBegin();
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    for (int i = 0; i < this->particles.size(); i ++) {
        Particle &p = this->particles.at(i);
        
        ofSetColor(255, 255, 255, 127.0f * p.life / p.startLife);
        ofDrawCircle(p.pos.x, p.pos.y, p.size);
        
        p.life -= delta / 100.0f;
        p.pos += p.dir * delta / 10000.0f * p.speed;
        
        if (p.life < 0 || p.pos.x < -p.size || p.pos.y < -p.size || p.pos.x > this->width + p.size || p.pos.y > this->height + p.size) {
            this->particles.erase(this->particles.begin() + i);
            if (this->particles.size() < this->guiNumOfParticles) {
                this->generateParticle();
            }
        }
    }
    
    ofDisableBlendMode();
    this->updateEnd();
}

void ParticleSystemLayer::clear() {
    this->particles.clear();
}

void ParticleSystemLayer::generateParticle() {
    Particle p;
    p.pos = ofVec2f(this->guiPosX, this->guiPosY);
    p.pos += ofVec2f(frnd(-this->guiSpread, this->guiSpread), frnd(-this->guiSpread, this->guiSpread));
    p.dir += ofVec2f(frnd(-this->guiSpread, this->guiSpread), frnd(-this->guiSpread, this->guiSpread));
    p.life = p.startLife = frnd(this->guiLifeMin, this->guiLifeMax);
    p.speed = frnd(this->guiSpeedMin, this->guiSpeedMax);
    p.size = frnd(this->guiSizeMin, this->guiSizeMax);
    this->particles.push_back(p);
}

void ParticleSystemLayer::displayGui() {
    ImGui::PushID(this->getLayerIdString().c_str());
    if (ImGui::CollapsingHeader((this->getName() + " (" + this->getLayerIdString() + ")").c_str())) {
        this->commonGui();
        this->customGui();
    }
    ImGui::PopID();
}

void ParticleSystemLayer::customGui() {
    ImGui::SliderInt("num of particles", &this->guiNumOfParticles, 10, 10000);
    ImGui::SliderFloat("pos X", &this->guiPosX, -this->width, this->width);
    ImGui::SliderFloat("pos Y", &this->guiPosY, -this->width, this->width);
    ImGui::SliderFloat("spread", &this->guiSpread, 0, this->width);
    ImGui::DragFloatRange2("life", &this->guiLifeMin, &this->guiLifeMax, 0.25f, 1.0f, 100.0f, "min: %.1f", "max: %.1f");
    ImGui::DragFloatRange2("speed", &this->guiSpeedMin, &this->guiSpeedMax, 1.0f, 1.0f, 1000.0f, "min: %.1f", "max: %.1f");
    ImGui::DragFloatRange2("size", &this->guiSizeMin, &this->guiSizeMax, 0.25f, 1.0f, 100.0f, "min: %.1f", "max: %.1f");
    
    if (this->particles.size() == 0) {
        if (ImGui::Button("GENERATE")) {
            this->create();
        }
    }
    if (this->particles.size() > 0) {
        if (ImGui::Button("CLEAR")) {
            this->particles.clear();
        }
    }
}
