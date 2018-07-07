#pragma once

namespace atlas {
    namespace gui {
        const int MOUSE_BUTTON_NONE = -1;
        const int MOUSE_BUTTON_LEFT = 0;
        const int MOUSE_BUTTON_RIGHT = 2;
        
        struct Events {
            int mouseX, mouseY, mouseButton;
            int key;
        };
    }
}
