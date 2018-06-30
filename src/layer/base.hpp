#pragma once

#include "libs/of.hpp"

namespace atlas {
    namespace layer {
        
        class Base {
        public:
            virtual void setup() = 0;
            virtual void update() = 0;
            virtual const ofTexture& getFrame() = 0;
        private:
            
        };
    }
}
