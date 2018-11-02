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
    return input;
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
    return input;
}

const json atlas::core::BpmModifier::saveJson() {
    json j;
    j["enabled"] = this->enabled;
    j["modified_by"] = this->modifiedBy;
    j["scale"] = this->scale;
    return j;
}

bool atlas::core::BpmModifier::loadJson(const json &j) {
    if (j.count("enabled") > 0) {
        this->enabled = j["enabled"].get<bool>();
    }
    if (j.count("modified_by") > 0) {
        this->modifiedBy = j["modified_by"].get<int>();
    }
    if (j.count("scale") > 0) {
        this->scale = j["scale"].get<float>();
    }
    return true;
}
