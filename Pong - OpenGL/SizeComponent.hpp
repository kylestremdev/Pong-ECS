//
//  ShapeComponent.hpp
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/4/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef ShapeComponent_h
#define ShapeComponent_h

#include "Components.hpp"

class SizeComponent : public Component {
public:
    SizeComponent() { init(); }
    
    int l() { return length; }
    int w() { return width; }
    
    void setSize(int l, int w) {
        length = l;
        width = w;
    }
    
private:
    PositionComponent *position;
    int length, width;
};


#endif /* ShapeComponent_h */
