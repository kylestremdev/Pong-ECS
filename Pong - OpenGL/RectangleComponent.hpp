//
//  RectangleComponent.h
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/4/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef RectangleComponent_h
#define RectangleComponent_h

#include "Components.hpp"
#include <GLUT/glut.h>
#include "Rect.hpp"


class RectangleComponent : public Component {
public:
    void init() override {
        position = &entity->getComponent<PositionComponent>();
        size = &entity->getComponent<SizeComponent>();
    }
    
    void draw() override {
        glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        // top right x + w, y + l
        glVertex2f((GLfloat) position->x() + size->w(), (GLfloat) position->y() + size->l());
        // top left x, y + l
        glVertex2f((GLfloat) position->x(), (GLfloat) position->y() + size->l());
        // bot left x, y
        glVertex2f((GLfloat) position->x(), (GLfloat) position->y());
        // bot right x + w, y
        glVertex2f((GLfloat) position->x() + size->w(), (GLfloat) position->y());
        glEnd();
        glPopMatrix();
    }
    
    Rect toRect() {
        return Rect(position->x(), position->y(), size->w(), size->l());
    }
    
private:
    PositionComponent *position;
    SizeComponent *size;
};

#endif /* RectangleComponent_h */
