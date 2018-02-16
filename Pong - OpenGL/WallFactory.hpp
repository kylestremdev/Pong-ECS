//
//  WallFactory.hpp
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/7/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef WallFactory_h
#define WallFactory_h

#include "Entities.hpp"

struct WallFactory {
    static Entity& createTopWall(EntityManager* em) {
        auto& wall(em->addEntity());
        wall.addComponent<PositionComponent>().setPos(0.0f, 390.0f);
        wall.addComponent<SizeComponent>().setSize(10, 600);
        wall.addComponent<WallComponent>(top);
        wall.addComponent<RectangleComponent>();
        wall.addComponent<CollidableComponent>("Wall");
        
        return wall;
    }
    
    static Entity& createBottomWall(EntityManager* em) {
        auto& wall(em->addEntity());
        wall.addComponent<PositionComponent>().setPos(0.0f, 0.0f);
        wall.addComponent<SizeComponent>().setSize(10, 600);
        wall.addComponent<WallComponent>(bottom);
        wall.addComponent<RectangleComponent>();
        wall.addComponent<CollidableComponent>("Wall");
        
        return wall;
    }
};

#endif /* WallFactory_h */
