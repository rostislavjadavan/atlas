#pragma once

namespace atlas {
    namespace core {
        struct AppSettings {
            int compositorOutputWidth = 800;
            int compositorOutputHeight = 600;
            
            float getHeightToWidthRatio() {
                return (float)this->compositorOutputHeight / (float)this->compositorOutputWidth;
            }
        };
    }
}
