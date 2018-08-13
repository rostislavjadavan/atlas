#include "app.hpp"
#include "../libs/json.hpp"

void atlas::core::App::setup() {
    this->settings.loadIfExists();
    
    this->container = std::make_shared<LayerContainer>();
    this->compositor = std::make_shared<LayerCompositor>(this->container, this->settings);
    
    this->outputWindow = std::make_shared<OutputWindow>();
    this->outputWindow->init();
    
    this->beatDetector = std::make_shared<ofxBeat>();
    ofSoundStreamSetup(0, 2, this->mainApp.get(), 44100, this->beatDetector->getBufferSize(), 4);
}

void atlas::core::App::update() {
    this->compositor->update();
    this->beatDetector->update(ofGetElapsedTimeMillis());
}


bool atlas::core::App::saveWorkspace(std::string name) {
    json j;
    j["version"] = this->getVersion();
    j["layers"] = this->getLayerContainer()->saveJson();
    
    const std::string outPath = ofToDataPath("workspace/" + name + ".json");
    ofFile out;
    out.open(outPath, ofFile::WriteOnly);
    ofLogNotice() << "[App] Workspace saved to " << outPath;
    return true;
}

bool atlas::core::App::loadWorkspace(std::string name) {
    ofFile file;
    if (file.open(ofToDataPath("workspace/" + name + ".json"), ofFile::ReadOnly, false)) {
        if (!file.exists()) {
            ofLogError() << "[App] file " + name + ".json does not exists";
            return false;
        }
        try {
            nlohmann::json config = nlohmann::json::parse(file.readToBuffer().getText());
            if (config.count("layers") > 0) {
                this->container->loadJson(config["layers"]);
            }
            
        } catch (const nlohmann::detail::parse_error &e) {
            ofLogError() << "[App] error parsing workspace " + name + ".json: " << e.what();
            return false;
        }
    }
    return true;
}

const std::vector<std::string> atlas::core::App::listSavedWorkspaces() {
    ofDirectory dir;
    std::vector<std::string> pathList;
    
    dir.open(ofToDataPath("workspace/"));
    dir.allowExt("json");
    
    const int size = (int)dir.listDir();
    if (size > 0) {
        for (int i = 0; i < dir.size(); i ++) {
            pathList.push_back(dir.getFile(i).getBaseName());
        }
    }
    return pathList;
}


