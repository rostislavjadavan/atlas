#pragma once

//
// https://stackoverflow.com/questions/686353/c-random-float-number-generation
//
inline float frnd(float lo, float hi) {
    return lo + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(hi-lo)));
}
