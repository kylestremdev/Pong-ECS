//
//  AIComponent.hpp
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/4/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef AIComponent_h
#define AIComponent_h

#include "Components.hpp"
#include "Game.hpp"

#include <algorithm>

class AIComponent : public Component {
public:
    void init() override {
        position = &entity->getComponent<PositionComponent>();
        velocity = &entity->getComponent<VelocityComponent>();
    }
    
    void update() override {
        if (ballPos->y() > position->y() + 30) {
            velocity->setVel(0, std::min(3.5f, 390.0f - position->y() + 50.0f) * std::max(1.0f, 5.0f / 600 - position->x()));
        } if (ballPos->y() < position->y() + 20) {
            velocity->setVel(0, std::max(-3.5f, 0.0f - position->y())  * std::max(1.0f, 5.0f / 600 - position->x()));
        }
    }
    
    void assignBall(Entity *b) {
        ball = b;
        ballPos = &ball->getComponent<PositionComponent>();
    }
    
private:
    PositionComponent *position;
    VelocityComponent *velocity;
    PositionComponent *ballPos;
    Entity *ball;
};


#endif /* AIComponent_h */
