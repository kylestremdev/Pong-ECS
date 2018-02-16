//
//  MovementComponent.hpp
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/4/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef MovementComponent_h
#define MovementComponent_h

#include "Components.hpp"

class MovementComponent : public Component {
public:
    void init() {
        position = &entity->getComponent<PositionComponent>();
        velocity = &entity->getComponent<VelocityComponent>();
    }
    
    void update() {
        
        if (position->x() < 0 || position->x() > 600 || position->y() < 0 || position->y() > 400) {
            return;
        }
        
        if (!moveUp && velocity->y() > 0) {
            position->add(velocity->x(), 0);
        } else if (!moveDown && velocity->y() < 0) {
            position->add(velocity->x(), 0);
        } else {
            moveUp = true;
            moveDown = true;
            position->add(*velocity->getVelocityVector());
        }
    }
    
    void canMoveUp(bool b) {
        moveUp = b;
    }
    
    void canMoveDown(bool b) {
        moveDown = b;
    }
    
    bool moveUp = true;
    bool moveDown = true;
    
private:
    PositionComponent *position;
    VelocityComponent *velocity;
};


#endif /* MovementComponent_h */
