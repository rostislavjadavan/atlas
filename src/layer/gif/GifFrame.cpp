#include "GifFrame.h"


GifFrame::GifFrame(uint32_t* data, int32_t delayMs, int32_t w, int32_t h) : data(data), delayMs(delayMs), w(w), h(h)
{
    
}

const ofTexture* GifFrame::getTexture() {
    if (this->texture == NULL) {
        this->texture = new ofTexture();
        this->texture->loadData((unsigned char*)data, w, h, GL_RGBA);
    }
    return this->texture;
}

GifFrame::~GifFrame(void)
{
}
