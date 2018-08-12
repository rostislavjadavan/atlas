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

    /*
    nlohmann::json j, l1, l2;
    j["compositor_width"] = 800;
    j["compositor_height"] = 600;
    
    l1["aaa"] = 1;
    l1["bbb"] = std::string("bbb");
    
    l2["aaa"] = 2;
    l2["bbb"] = std::string("bbb");
    
    j["layer"] = nlohmann::json::array({});
    j["layer"].push_back(l1);
    j["layer"].push_back(l2);
    
    std::string out = j.dump();
    ofLogNotice() << out;
    
    nlohmann::json i = nlohmann::json::parse(out);
    ofLogNotice() << i["compositor_width"];
    
    for (auto& element : i["layer"]) {
        if (element.count("aaa") > 0)
            ofLogNotice() << element["aaa"].get<int>() << '\n';
        if (element.count("bbb") > 0)
            ofLogNotice() << element["bbb"].get<std::string>() << '\n';
        if (element.count("ccc") > 0)
            ofLogNotice() << element["ccc"].get<std::string>() << '\n';
    }
    */
}

void atlas::core::App::update() {
    this->compositor->update();
    this->beatDetector->update(ofGetElapsedTimeMillis());
}

