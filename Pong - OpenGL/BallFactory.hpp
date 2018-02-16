//
//  BallFactory.hpp
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/7/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef BallFactory_h
#define BallFactory_h

#include "Entities.hpp"

struct BallFactory {
    static Entity& createBall(EntityManager* em) {
        auto& ball(em->addEntity());
        ball.addComponent<PositionComponent>().setPos(300.0f, 200.0f);
        ball.addComponent<SizeComponent>().setSize(20, 20);
        ball.addComponent<VelocityComponent>().setVel(2.0f,3.0f);
        ball.addComponent<BallComponent>(10);
        ball.addComponent<CollidableComponent>("Ball");
        ball.addComponent<MovementComponent>();
        
        return ball;
    }
};


#endif /* BallFactory_h */
