//
//  WallComponent.hpp
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/4/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef WallComponent_h
#define WallComponent_h

#include "Components.hpp"

enum WallType {
    top,
    bottom
};

class WallComponent : public Component {
public:
    
    WallComponent(WallType type): wallType(type) {};
    
    WallType getWallType() {
        return wallType;
    }
private:
    WallType wallType;
};

#endif /* WallComponent_h */
