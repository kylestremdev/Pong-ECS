//
//  PlayerComponent.hpp
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/4/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef PlayerComponent_h
#define PlayerComponent_h

#include "Components.hpp"

class PlayerComponent : public Component {
public:
    void handleKeyDown(unsigned char key) override {
        switch(key) {
            case 'w':
                if (entity->getComponent<MovementComponent>().moveUp) {
                    entity->getComponent<VelocityComponent>().setVel(0, 5);
                }
                break;
            case 's':
                if (entity->getComponent<MovementComponent>().moveDown) {
                    entity->getComponent<VelocityComponent>().setVel(0, -5);
                }
        }
    }
    
    void handleKeyUp(unsigned char key) override {
        switch(key) {
            case 'w':
                if (entity->getComponent<MovementComponent>().moveUp) {
                    entity->getComponent<VelocityComponent>().setVel(0, 0);
                }
                break;
            case 's':
                if (entity->getComponent<MovementComponent>().moveDown) {
                    entity->getComponent<VelocityComponent>().setVel(0, 0);
                }
        }
    }
};


#endif /* PlayerComponent_h */
