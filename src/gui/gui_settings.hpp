#pragma once

#include <string>
#include "../libs/of.hpp"

namespace atlas {
    namespace gui {
        struct GuiSettings {
            std::string appName = "AtlasVJ";
            std::string lastMediaSelectorDirectory = ofFilePath::getUserHomeDir();
        };
    }
}
