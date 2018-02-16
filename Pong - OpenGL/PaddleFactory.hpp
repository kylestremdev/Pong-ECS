//
//  PaddleFactory.hpp
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/7/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef PaddleFactory_h
#define PaddleFactory_h

#include "Entities.hpp"

struct PaddleFactory {
    static Entity& createLeftPaddle(EntityManager* em) {
        auto& paddle(em->addEntity());
        paddle.addComponent<PositionComponent>().setPos(0.0f, 175.0f);
        paddle.addComponent<VelocityComponent>().setVel(0.0f, 0.0f);
        paddle.addComponent<SizeComponent>().setSize(50, 20);
        paddle.addComponent<RectangleComponent>();
        paddle.addComponent<CollidableComponent>("Paddle");
        paddle.addComponent<MovementComponent>();
        paddle.addComponent<PlayerComponent>();
        
        return paddle;
    }
    
    static Entity& createRightPaddle(EntityManager* em, Entity* ball) {
        auto& paddle(em->addEntity());
        paddle.addComponent<PositionComponent>().setPos(580.0f, 150.0f);
        paddle.addComponent<VelocityComponent>().setVel(0.0f, 0.0f);
        paddle.addComponent<SizeComponent>().setSize(50, 20);
        paddle.addComponent<RectangleComponent>();
        paddle.addComponent<CollidableComponent>("Paddle");
        paddle.addComponent<MovementComponent>();
        paddle.addComponent<AIComponent>().assignBall(ball);
        
        return paddle;
    }
};


#endif /* PaddleFactory_h */
