#pragma once

#include "constants.hpp"

namespace atlas {
    namespace core {
        class BpmModifier {
        public:
            bool enabled;
            int modifiedBy;
            float scale;
            
            BpmModifier();
            float applyMultiply(float intput);
            float applyAdd(float intput);
        };
    }
}
