#pragma once

#include "../../libs/of.hpp"
#include <vector>

namespace atlas {
    namespace layer {
        namespace libs {
            
            class LinearTimeline {
            public:
                LinearTimeline() {
                }
                
                void add(const ofVec2f &p) {
                    this->points.push_back(p);
                }
                
                void set(int i, const ofVec2f &p) {
                    this->points.at(i) = p;
                }
                
                void update(float delta) {
                    this->time += delta / 100.0f;
                }
                
                void reset() {
                    this->time = 0.0f;
                }
                
                float getTime() {
                    return this->time;
                }
                
                float get() {
                    float pointTime = 0;
                    for(int i = 1; i < this->points.size(); i ++) {
                        pointTime += this->points.at(i).x;
                        if (time < pointTime) {
                            const ofVec2f a = this->points.at(i - 1);
                            const ofVec2f b = this->points.at(i);
                            return this->interpolate((time - pointTime + b.x) / b.x, a, b).y;
                        }
                    }
                    this->reset();
                    return this->points.back().y;
                }
                
            private:
                std::vector<ofVec2f> points;
                float time;
                
                const ofVec2f interpolate(const float t, const ofVec2f &a, const ofVec2f &b) {
                    return b * t + a * (1 - t);
                }
            };
        }
    }
}
