//
//  BallComponent.hpp
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/4/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef BallComponent_h
#define BallComponent_h

#include "Components.hpp"
#include <GLUT/glut.h>
#include <cmath>
#include <iostream>
#include "Rect.hpp"

class BallComponent : public Component {
public:
    BallComponent(int r) : radius(r) {};
    
    void init() override {
        position = &entity->getComponent<PositionComponent>();
    }
    
    void draw() override {
        
        if (position->x() < 0 || position->x() > 600 || position->y() < 0 || position->y() > 400) {
            return;
        }
        
        glPushMatrix();
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i < 100; i++)
        {
            float theta = 2.0f * 3.1415926f * float(i) / float(100);//get the current angle
            
            float x = radius * cosf(theta);//calculate the x component
            float y = radius * sinf(theta);//calculate the y component
            
            glVertex2f(x + position->x() + radius, y + position->y() + radius);//output vertex
            
        }
        glEnd();
        glPopMatrix();
    }
    
private:
    PositionComponent *position;
    int radius;
};


#endif /* BallComponent_h */
