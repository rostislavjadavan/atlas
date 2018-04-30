
#include "LayerCompositor.h"

LayerCompositor::LayerCompositor(std::shared_ptr<ApplicationSettings> settings) {
	this->pSettings = settings;
	this->fbo.allocate(settings->compositorWidth, settings->compositorHeight, GL_RGBA);
}

LayerCompositor::~LayerCompositor() { }

ofFbo LayerCompositor::render(std::shared_ptr<LayerManager> manager) {
	fbo.begin();
	ofClear(0, 0, 0, 0);

	for (int i = 0; i < manager->count(); i++) {
		LayerInfo info = manager->get(i)->getInfo();
		
		ofEnableBlendMode(info.blendMode);
		ofSetColor(255, 255, 255, (int)(255 * info.alpha));

        manager->get(i)->getOutput().draw(info.posX, info.posY, info.width, info.height);

        ofSetColor(255, 255, 255);
        ofDisableBlendMode();
    }

    fbo.end();
    return fbo;
}
