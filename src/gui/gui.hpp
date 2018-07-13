
#include "gui_settings.hpp"
#include "types.hpp"
#include "view/layers.hpp"
#include "view/preview.hpp"
#include "view/properties.hpp"
#include "view/output.hpp"
#include "view/system.hpp"
#include "../core/app.hpp"
#include "../libs/of.hpp"

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
            void draw();
            
            Events events;
            
            void onKeyReleased(ofKeyEventArgs& event);
            void onKeyPressed(ofKeyEventArgs& event);
            void onMousePressed(ofMouseEventArgs& event);
            void onMouseReleased(ofMouseEventArgs& event);
            void onMouseMove(ofMouseEventArgs& event);
            
        private:
            Gui() {}
            ~Gui() {}
            
            GuiSettings settings;
            ofxImGui::Gui gui;
            
            int selectedLayer;
            
            view::Layers layersView;
            view::Preview previewView;
            view::Output outputView;
            view::System systemView;
            view::Properties propertiesView;
        };
    }
}
