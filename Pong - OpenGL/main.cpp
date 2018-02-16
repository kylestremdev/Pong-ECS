//
//  main.cpp
//  Pong - OpenGL
//
//  Created by Kyle Strem on 11/10/17.
//  Copyright © 2017 Kyle Strem. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include "Game.hpp"

#include "ECS.hpp"
#include "Components.hpp"
#include "Systems.hpp"
#include "Entities.hpp"


Game game;

void initGL() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    game.init();
}

void display() {
    
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    game.draw();
    
    glutSwapBuffers();
    glFlush();
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(0.0, (GLdouble) 600, 0.0, (GLdouble) 400);
    
}

void Timer(int value) {
    game.update();
    glutTimerFunc(20, Timer, 0); // subsequent timer call at milliseconds
}

void mouse(int button, int state, int x, int y) {
    game.mouse(button, state, x, y);
}

void keyDown(unsigned char key, int x, int y) {
    game.keyDown(key);
}

void keyUp(unsigned char key, int x, int y) {
    game.keyUp(key);
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Pong");
    initGL();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, Timer, 0);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);
    
    
    glutMainLoop();
    return 0;
}

