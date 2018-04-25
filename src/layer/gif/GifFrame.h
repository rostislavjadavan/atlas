#pragma once

#include "ofMain.h"
#include <stdint.h>

class GifFrame
{
public:
	GifFrame(uint32_t* data, int32_t delayMs, int32_t w, int32_t h);
	~GifFrame(void);

    const int w, h;
	const uint32_t* data;
	const int32_t delayMs;
    const ofTexture* getTexture();
    void freeTexture();
    
private:
    ofTexture *texture = NULL;
};

