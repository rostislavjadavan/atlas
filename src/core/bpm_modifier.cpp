#include "bpm_modifier.hpp"
#include "app.hpp"

atlas::core::BpmModifier::BpmModifier() {
    this->enabled = false;
    this->modifiedBy = BPM_KICK;
    this->scale = 1.0f;
}

float atlas::core::BpmModifier::applyMultiply(float input) {
    if (!this->enabled) {
        return input;
    }
    if (this->modifiedBy == atlas::core::BPM_KICK) {
        return atlas::core::App::instance().getBeatDetector()->kick() * input * this->scale;
    }
    if (this->modifiedBy == atlas::core::BPM_SNARE) {
        return atlas::core::App::instance().getBeatDetector()->snare() * input * this->scale;
    }
    if (this->modifiedBy == atlas::core::BPM_HIHAT) {
         return atlas::core::App::instance().getBeatDetector()->hihat() * input * this->scale;
    }
}

float atlas::core::BpmModifier::applyAdd(float input) {
    if (!this->enabled) {
        return input;
    }
    if (this->modifiedBy == atlas::core::BPM_KICK) {
        return input + atlas::core::App::instance().getBeatDetector()->kick() * this->scale;
    }
    if (this->modifiedBy == atlas::core::BPM_SNARE) {
        return input + atlas::core::App::instance().getBeatDetector()->snare() * this->scale;
    }
    if (this->modifiedBy == atlas::core::BPM_HIHAT) {
        return input + atlas::core::App::instance().getBeatDetector()->hihat() * this->scale;
    }
}
