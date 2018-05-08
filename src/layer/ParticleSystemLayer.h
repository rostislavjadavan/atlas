#pragma once

#include "ofMain.h"
#include "FboLayer.h"
#include "utils/Random.h"

class ParticleSystemLayer: public FboLayer {
public:
    ParticleSystemLayer(int width, int height);
    ~ParticleSystemLayer();
    
    void update();
    void clear();
    std::string getName() {
        return "ParticleSystem";
    }
    
protected:    
    struct Particle {
        ofVec2f pos, dir;
        float size, speed, life, startLife;
    };
    
    std::vector<Particle> particles;
    
    void create();
    void generateParticle();
    
    float guiPosX, guiPosY;
    float guiSpread;
    float guiLifeMin, guiLifeMax;
    float guiSpeedMin, guiSpeedMax;
    float guiSizeMin, guiSizeMax;
    int guiNumOfParticles;
    
    void displayGui();
    void customGui();
};
