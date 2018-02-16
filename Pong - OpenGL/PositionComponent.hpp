//
//  PositionComponent.h
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/4/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef PositionComponent_h
#define PositionComponent_h

#include "Components.hpp"
#include "Vec2.hpp"
#include <iostream>

class PositionComponent : public Component {
public:
    float x() { return xpos; }
    float y() { return ypos; }
    
    void init() override {
        xpos = 0;
        ypos = 0;
    }
    
    void setPos(float x, float y) {
        xpos = x;
        ypos = y;
    }
    void add(float x, float y) {
        xpos += x;
        ypos += y;
    }
    
    void add(Vec2f vec) {
        xpos += vec.x;
        ypos += vec.y;
    }
    
private:
    float xpos = 0;
    float ypos = 0;
};


#endif /* PositionComponent_h */
