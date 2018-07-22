#pragma once

#include "../../libs/of.hpp"

namespace atlas {
    namespace gui {
        namespace view {
            enum MediaSelectorMode {
                FILE_SELECT, DIR_SELECT
            };
            
            class MediaSelector {
            public:
                MediaSelector();
                bool draw();
                bool draw(ofRectangle rect);
                ofFile getSelected() {
                    return this->selectedMedia;
                }
                void setMode(MediaSelectorMode mode) {
                    this->mode = mode;
                }
                
            protected:
                bool display = false;
                ofFile selectedMedia;
                
                ofDirectory dir;
                std::string currentPath;
                std::vector<ofFile> fileList;
                MediaSelectorMode mode;
                
                char pathInput[512];
                
                void drawDirectoryInput();
                bool drawList();
                
                bool setPath(std::string path);
                void goDirUp();
            };
        }
    }
}
