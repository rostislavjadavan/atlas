#pragma once

#include "base.hpp"

namespace atlas {
    namespace layer {
        class FboCanvas : public Base {
        public:
            void setup();
            void update(double delta);
            const std::shared_ptr<ofFbo>& getFrame();
            
        protected:
            /*double getDelta() {
                return this->delta;
            }*/
            
        private:
            std::shared_ptr<ofFbo> fbo;
            //double lastElapsedTime = 0;
            //double delta = 0;
        };
    }
}
