
#include "../libs/of.hpp"
#include <string>

namespace atlas {
    namespace gui {
        
        class Gui {
        public:
            static Gui& instance() {
                static Gui myInstance;
                return myInstance;
            }
            
            Gui(Gui const&) = delete;
            Gui(Gui&&) = delete;
            Gui& operator=(Gui const&) = delete;
            Gui& operator=(Gui &&) = delete;
            void setup();
            
        private:
            Gui() {}
            ~Gui() {}
            
            std::string appName = "Atlas Compositor";
            ofxImGui::Gui gui;
        };
    }
}
