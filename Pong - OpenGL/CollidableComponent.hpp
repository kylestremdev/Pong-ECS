//
//  CollidableComponent.hpp
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/4/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef CollidableComponent_h
#define CollidableComponent_h

#include "Components.hpp"
#include "Rect.hpp"

class CollidableComponent : public Component {
public:
    CollidableComponent(std::string t) {
        tag = t;
    }
    
    void init() override {
        position = &entity->getComponent<PositionComponent>();
        size = &entity->getComponent<SizeComponent>();
        collisionBox.setRect(position->x(), position->y(), size->w(), size->l());
    }
    
    Rect* getCollisionBox() {
        collisionBox.setRect(position->x(), position->y(), size->w(), size->l());
        return &collisionBox;
    }
    
    std::string tag;
    
private:
    PositionComponent *position;
    SizeComponent *size;
    Rect collisionBox = Rect(0, 0, 0, 0);
};


#endif /* CollidableComponent_h */
