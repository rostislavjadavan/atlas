#include "GifFrame.h"


GifFrame::GifFrame(uint32_t* data, int32_t delayMs, int32_t w, int32_t h) : data(data), delayMs(delayMs)
{
    this->texture.loadData((unsigned char*)data, w, h, GL_RGBA);
}


GifFrame::~GifFrame(void)
{
}
