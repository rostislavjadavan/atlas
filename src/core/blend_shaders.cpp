#include "blend_shaders.hpp"

const std::string atlas::core::BlendShaders::IMGUI_COMBO_STRING = "NORMAL\0MULTIPLY\0AVERAGE\0ADD\0SUBTRACT\0DIFF\0NEGATION\0EXCLUSION\0SCREEN\0OVERLAY\0SOFTLIGHT\0HARDLIGHT\0COLORODGE\0COLORBURN\0LINEARLIGHT\0VIVIDLIGHT\0PINLIGHT\0HARDMIX\0REFLECT\0GLOW\0PHOENIX\0HUE\0SATURATION\0COLOR\0LUMINOSITY";

void atlas::core::BlendShaders::setup() {
    if (ofIsGLProgrammableRenderer())
    {
        this->shader.setupShaderFromSource(GL_VERTEX_SHADER, psBlendVertShaderGL3);
        this->shader.setupShaderFromSource(GL_FRAGMENT_SHADER, psBlendFragShaderGL3);
        this->shader.bindDefaults();
    }
    else
    {
        this->shader.setupShaderFromSource(GL_FRAGMENT_SHADER, psBlendFragShaderGL2);
    }
    this->shader.linkProgram();
}

void atlas::core::BlendShaders::begin(const ofTexture &base, const ofTexture &blend, int blendMode) {
    this->shader.begin();
    this->shader.setUniformTexture("base", base, 1);
    this->shader.setUniformTexture("blendTgt", blend, 2);
    this->shader.setUniform1i("mode", blendMode);
}

void atlas::core::BlendShaders::end() {
    this->shader.end();
}
