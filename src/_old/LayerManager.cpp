
#include "LayerManager.h"

LayerManager::LayerManager(std::shared_ptr<ApplicationSettings> settings) {
	this->pSettings = settings;
}

LayerManager::~LayerManager() {}

void LayerManager::add(std::shared_ptr<AbstractLayer> layer) {
	this->layerList.push_back(layer);
}

void LayerManager::add(AbstractLayer *layer) {
	this->layerList.push_back(std::shared_ptr<AbstractLayer>(layer));
}

int LayerManager::count() {
	return this->layerList.size();
}

std::shared_ptr<AbstractLayer> LayerManager::get(int i) {
	return this->layerList.at(i);
}

void LayerManager::layersSetup() {
	std::vector<std::shared_ptr<AbstractLayer>>::iterator iter, end;
	for(iter = this->layerList.begin(), end = this->layerList.end(); iter != end; ++iter) {
		(*iter)->setup();
	}
}

void LayerManager::layersUpdate() {
	std::vector<std::shared_ptr<AbstractLayer>>::iterator iter, end;
	for(iter = this->layerList.begin(), end = this->layerList.end(); iter != end; ++iter) {
		(*iter)->update();
	}
}

void LayerManager::displayGui() {
	if (ImGui::CollapsingHeader("Layers")) {
		this->createGui();
		this->moveGui();
		this->deleteGui();

		std::vector<std::shared_ptr<AbstractLayer>>::iterator iter, end;
		for(iter = this->layerList.begin(), end = this->layerList.end(); iter != end; ++iter) {
			(*iter)->displayGui();
		}
	}
}

void LayerManager::createGui() {
    ImGui::Text("create layer");
    if (ImGui::Button("GIF")) {
        GifLayer *l = new GifLayer(this->pSettings->compositorWidth, this->pSettings->compositorHeight);
        l->setup();
        this->add(l);
    }
    ImGui::SameLine();
    if (ImGui::Button("GIF_DIR")) {
        GifDirectoryLayer *l = new GifDirectoryLayer(this->pSettings->compositorWidth, this->pSettings->compositorHeight);
        l->setup();
        this->add(l);
    }
    ImGui::SameLine();
    if (ImGui::Button("PARTICLES")) {
        ParticleSystemLayer *l = new ParticleSystemLayer(this->pSettings->compositorWidth, this->pSettings->compositorHeight);
        l->setup();
        this->add(l);
    }
    ImGui::SameLine();
    if (ImGui::Button("TEXT")) {
        TextLayer *l = new TextLayer(this->pSettings->compositorWidth, this->pSettings->compositorHeight);
        l->setup();
        this->add(l);
    }
}

void LayerManager::moveGui() {
	if (ImGui::TreeNode("move layer")) {
		int counter = 0;
		std::vector<std::shared_ptr<AbstractLayer>>::iterator iter, end;

		for(iter = this->layerList.begin(), end = this->layerList.end(); iter != end; ++iter) {
			ImGui::PushID((*iter)->getLayerIdString().c_str());
			ImGui::Text((*iter)->getLayerIdString().c_str());
			ImGui::SameLine();

			if (ImGui::Button("UP")) { 
				int nextIndex = counter - 1;
				if (nextIndex < 0) {
					nextIndex = this->count() - 1;
				}
				std::swap(this->layerList.at(counter), this->layerList.at(nextIndex));
			}
			ImGui::SameLine();

			if (ImGui::Button("DOWN")) { 
				int nextIndex = counter + 1;
				if (nextIndex >= this->count()) {
					nextIndex = 0;
				}
				std::swap(this->layerList.at(counter), this->layerList.at(nextIndex));
			}
			counter++;
			ImGui::PopID();
		}		
		ImGui::TreePop();
	}
}

void LayerManager::deleteGui() {
	if (ImGui::TreeNode("delete layer")) {
		std::vector<std::shared_ptr<AbstractLayer>>::iterator iter, end;
		for(iter = this->layerList.begin(), end = this->layerList.end(); iter != end; ++iter) {
			std::string label = "delete " + (*iter)->getLayerIdString();
			if (ImGui::Button(label.c_str())) { 
				this->layerList.erase(iter);
				break;
			}
		}
		ImGui::TreePop();
	}
}
