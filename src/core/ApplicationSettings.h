#pragma once

struct ApplicationSettings {
	int compositorWidth, compositorHeight;
    
    float getHeightToWidthRatio() {
        return (float)this->compositorHeight / (float)this->compositorWidth;
    }
};
