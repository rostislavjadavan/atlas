#pragma once

#include "libs/of.hpp"

namespace atlas {
    namespace layer {
        
        class Base {
        public:
            virtual void setup() = 0;
            virtual void update(double delta) = 0;
            virtual const std::shared_ptr<ofFbo>& getFrame() = 0;
        private:
            
        };
    }
}
