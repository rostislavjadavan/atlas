#include "gui.hpp"

void atlas::gui::Gui::setup() {
    ofSetWindowTitle(this->settings.appName);
    
    this->events.mouseButton = MOUSE_BUTTON_NONE;
    
    ofAddListener(ofEvents().mousePressed, this, &atlas::gui::Gui::onMousePressed);
    ofAddListener(ofEvents().mouseReleased, this, &atlas::gui::Gui::onMouseReleased);
    ofAddListener(ofEvents().mouseMoved, this, &atlas::gui::Gui::onMouseMove);
    ofAddListener(ofEvents().keyReleased, this, &atlas::gui::Gui::onKeyReleased);
    ofAddListener(ofEvents().keyPressed, this, &atlas::gui::Gui::onKeyPressed);
    
    this->gui.setup();
    
    ImGuiStyle * style = &ImGui::GetStyle();
    
    style->WindowPadding = ImVec2(15, 15);
    style->WindowRounding = 0.0f;
    style->FramePadding = ImVec2(5, 5);
    style->FrameRounding = 0.0f;
    style->ItemSpacing = ImVec2(12, 8);
    style->ItemInnerSpacing = ImVec2(8, 6);
    style->IndentSpacing = 25.0f;
    style->ScrollbarSize = 15.0f;
    style->ScrollbarRounding = 0.0f;
    style->GrabMinSize = 5.0f;
    style->GrabRounding = 3.0f;
    
    style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
    style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
    style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
    style->Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
    style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
    style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
    style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
    style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
    style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
    style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
    style->Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
    style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
    style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
    style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
    style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
    style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
    style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
    style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
    style->Colors[ImGuiCol_ComboBg] = ImVec4(0.19f, 0.18f, 0.21f, 1.00f);
    style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
    style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
    style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
    style->Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
    style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
    style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
    style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
    style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
    style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
    style->Colors[ImGuiCol_Column] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
    style->Colors[ImGuiCol_ColumnHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
    style->Colors[ImGuiCol_ColumnActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
    style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
    style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
    style->Colors[ImGuiCol_CloseButton] = ImVec4(0.40f, 0.39f, 0.38f, 0.16f);
    style->Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.40f, 0.39f, 0.38f, 0.39f);
    style->Colors[ImGuiCol_CloseButtonActive] = ImVec4(0.40f, 0.39f, 0.38f, 1.00f);
    style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
    style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
    style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
    style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
    style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
    style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);
}

void atlas::gui::Gui::draw() {
    ofClear(100);
    
    const int width = ofGetWidth();
    const int height = ofGetHeight();
    const float compositorRatio = atlas::core::App::instance().settings.getHeightToWidthRatio();
    
    //
    // Layers
    //
    const float layersWidth = width / 3;
    const float layerHeight = layersWidth * compositorRatio;
    
    this->layersView.draw(ofRectangle(0, 0, layersWidth - 1, layerHeight), this->events);
    this->selectedLayer = this->layersView.getSelectedLayer();
    
    //
    // Preview
    //
    const float previewWidth = width / 3;
    const float previewHeight = previewWidth * compositorRatio;
    
    this->previewView.draw(ofRectangle(layersWidth, 0, previewWidth - 1, previewHeight), this->selectedLayer);
    
    //
    // Output
    //
    const float outputWidth = width / 3;
    const float outputHeight = outputWidth * compositorRatio;
    
    ofSetColor(0, 0, 0);
    ofDrawRectangle(layersWidth + previewWidth, 0, outputWidth, outputHeight);
    
    //
    // Properties
    //
    this->gui.begin();
    
    this->propertiesView.draw(ofRectangle(0, layerHeight + 1, layersWidth + previewWidth, height - layerHeight), this->selectedLayer);
    
    this->gui.end();
}

void atlas::gui::Gui::onKeyReleased(ofKeyEventArgs& event) {
    // TODO
}

void atlas::gui::Gui::onKeyPressed(ofKeyEventArgs& event) {
    // TODO
}

void atlas::gui::Gui::onMousePressed(ofMouseEventArgs& event) {
    this->events.mouseButton = event.button;
}

void atlas::gui::Gui::onMouseReleased(ofMouseEventArgs& event) {
    this->events.mouseButton = MOUSE_BUTTON_NONE;
}

void atlas::gui::Gui::onMouseMove(ofMouseEventArgs& event) {
    this->events.mouseX = event.x;
    this->events.mouseY = event.y;
}
