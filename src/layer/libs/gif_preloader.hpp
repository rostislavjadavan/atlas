#pragma once

#include "preloader_base.hpp"
#include "../../libs/of.hpp"
#include "../../libs/gif/GifDecoder.h"
#include <string>
#include <future>

namespace atlas {
    namespace layer {
        namespace libs {
            class GifPreloader: public PreloaderBase {
            public:
                void preload(std::string path);
                int getStatus();
                std::shared_ptr<GifDecoder> get();
                
            protected:
                int status = 0;
                std::future<std::shared_ptr<GifDecoder>> fpGifDecoder;
            };
        }
    }
}


