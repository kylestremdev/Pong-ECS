//
//  PhysicsSystem.hpp
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/4/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef PhysicsSystem_h
#define PhysicsSystem_h

#include "Systems.hpp"
#include <iostream>

class PhysicsSystem : public System {
public:
    PhysicsSystem(EntityManager* em): System(em) {}
    
    void update() override {
        // update positions
        entityManager->update();
        // handle collisions
        for(int i = 0; i < entityManager->entities.size() - 1; i++) {
            for(int j = 1; j < entityManager->entities.size(); j++) {
                auto& e1 = entityManager->entities[i];
                auto& e2 = entityManager->entities[j];
                
                if (e1->hasComponent<CollidableComponent>() && e2->hasComponent<CollidableComponent>()) {
                    CollidableComponent *c1 = &e1->getComponent<CollidableComponent>();
                    CollidableComponent *c2 = &e2->getComponent<CollidableComponent>();

                    Rect *rec1 = c1->getCollisionBox();
                    Rect *rec2 = c2->getCollisionBox();
                    
                    if ((rec1->x <= rec2->x + rec2->w) &&
                        (rec2->x <= rec1->x + rec1->w) &&
                        (rec1->y <= rec2->y + rec2->l) &&
                        (rec2->y <= rec1->y + rec1->l)) {
                        
                        if (c1->tag == "Ball" && c2->tag == "Paddle") {
                            // ball - paddle
                            e1->getComponent<VelocityComponent>().reverseX();
                            e1->getComponent<VelocityComponent>().multX(1.1);
                            return;
                        }
                        if (c1->tag == "Paddle" && c2->tag == "Ball") {
                            // paddle - ball
                            e2->getComponent<VelocityComponent>().reverseX();
                            e2->getComponent<VelocityComponent>().multX(1.1);
                            return;
                        }
                        if (c1->tag == "Ball" && c2->tag == "Wall") {
                            // ball - wall
                            e1->getComponent<VelocityComponent>().reverseY();
                            e1->getComponent<VelocityComponent>().multY(1.1);
                            return;
                        }
                        if (c1->tag == "Wall" && c2->tag == "Ball") {
                            // wall - ball
                            e2->getComponent<VelocityComponent>().reverseY();
                            e2->getComponent<VelocityComponent>().multY(1.1);
                            return;
                        }
                        if (c1->tag == "Paddle" && c2->tag == "Wall") {
                            // paddle - wall
                            if (e2->getComponent<WallComponent>().getWallType() == top) {
                                e1->getComponent<MovementComponent>().canMoveUp(false);
                                return;
                            } else if (e2->getComponent<WallComponent>().getWallType() == bottom) {
                                e1->getComponent<MovementComponent>().canMoveDown(false);
                                return;
                            }
                        }
                        if (c1->tag == "Wall" && c2->tag == "Paddle") {
                            // wall - paddle
                            if (e1->getComponent<WallComponent>().getWallType() == top) {
                                e2->getComponent<MovementComponent>().canMoveUp(false);
                                return;
                            } else if (e1->getComponent<WallComponent>().getWallType() == bottom) {
                                e2->getComponent<MovementComponent>().canMoveDown(false);
                                return;
                            }
                        }
                    } // end collision check
                } // end collidable check
            } // end inner loop
        } // end outer loop
    }
};


#endif /* PhysicsSystem_h */
