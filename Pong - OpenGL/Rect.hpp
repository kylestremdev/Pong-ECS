//
//  Rect.hpp
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/4/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef Rect_h
#define Rect_h

#include <iostream>

struct Rect {
    Rect(float _x, float _y, float _w, float _l): x(_x), y(_y), w(_w), l(_l) {};
    
    void setRect(float _x, float _y, float _w, float _l) {
        x = _x;
        y = _y;
        w = _w;
        l = _l;
    }
    
    float x, y, w, l;
    
    friend std::ostream& operator<< (std::ostream& stream, const Rect& rec) {
        stream << "{" << rec.x << "," << rec.y << "," << rec.l << "," << rec.w << "}";
        return stream;
    }
};


#endif /* Rect_h */
