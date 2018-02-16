//
//  Game.hpp
//  Pong - OpenGL
//
//  Created by Kyle Strem on 12/7/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <iostream>
#include <string>
#include <algorithm>

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include "ECS.hpp"
#include "Components.hpp"
#include "Systems.hpp"
#include "Entities.hpp"

enum GameState {
    menu,
    play,
    pause,
    over
};

class Game {
public:
    Game() {}
    
    void init() {
        playPhys = new PhysicsSystem(&playEM);
        ball = &BallFactory::createBall(&playEM);
        leftPaddle = &PaddleFactory::createLeftPaddle(&playEM);
        rightPaddle = &PaddleFactory::createRightPaddle(&playEM, ball);
        topWall = &WallFactory::createTopWall(&playEM);
        bottomWall = &WallFactory::createBottomWall(&playEM);
    }
    
    void update() {
        switch (state) {
            case play:
                playPhys->update();
                
                std::cout << ball->getComponent<VelocityComponent>().y() << std::endl;
                
                if (ball->getComponent<VelocityComponent>().y() > 6.0f) {
                    ball->getComponent<VelocityComponent>().setY(6.0f);
                } else if (ball->getComponent<VelocityComponent>().y() < -6.0f) {
                    ball->getComponent<VelocityComponent>().setY(-6.0f);
                }
                
                if (ball->getComponent<VelocityComponent>().x() > 6.0f) {
                    ball->getComponent<VelocityComponent>().setX(6.0f);
                } else if (ball->getComponent<VelocityComponent>().x() < -6.0f) {
                    ball->getComponent<VelocityComponent>().setX(-6.0f);
                }
                
                glutPostRedisplay();
                break;
            default:
                break;
        }
    }
    
    void draw() {
        switch (state) {
            case play:
                playEM.draw();
                break;
            default:
                break;
        }
    }
    
    void keyDown(unsigned char key) {
        switch (state) {
            case play:
                playEM.keyDown(key);
                break;
            default:
                break;
        }
    }
    
    void keyUp(unsigned char key) {
        switch (state) {
            case play:
                playEM.keyUp(key);
                break;
            default:
                break;
        }
    }
    
    void mouse(int button, int mstate, int x, int y) {
        switch (state) {
            case play:
                playEM.mouse(button, mstate, x, y);
                break;
            default:
                break;
        }
    }
    
private:
    EntityManager menuEM;
    EntityManager playEM;
    EntityManager pauseEM;
    EntityManager overEM;
    PhysicsSystem* playPhys;
//    ScoreSystem score;
    Entity* ball = 0;
    Entity* leftPaddle;
    Entity* rightPaddle;
    Entity* topWall;
    Entity* bottomWall;
    
    GameState state = play;
};


#endif /* Game_h */
