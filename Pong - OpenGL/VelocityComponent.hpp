//
//  VelocityComponent.hpp
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/4/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef VelocityComponent_h
#define VelocityComponent_h

#include "Components.hpp"
#include "Vec2.hpp"

class VelocityComponent : public Component {
public:
    float x() { return vel.x; }
    float y() { return vel.y; }
    Vec2f* getVelocityVector() { return &vel; }
    
    void init() override {
        vel.x = 0;
        vel.y = 0;
    }
    
    void setVel(float x, float y) {
        vel.x = x;
        vel.y = y;
    }
    
    void reverseX() { vel.x *= -1; }
    void reverseY() {
        vel.y *= -1;
    }
    
    void multX(float s) {
        vel.x *= s;
    }
    
    void multY(float s) {
        vel.y *= s;
    }
    
    void setX(float x) {
        vel.x = x;
    }
    
    void setY(float y) {
        vel.y = y;
    }
    
    void add(float x, float y) {
        vel.x += x;
        vel.y += y;
    }
    
    void add(Vec2f vec) {
        vel.x += vec.x;
        vel.y += vec.y;
    }
    
private:
    Vec2f vel = Vec2f(0.0f, 0.0f);
};


#endif /* VelocityComponent_h */
