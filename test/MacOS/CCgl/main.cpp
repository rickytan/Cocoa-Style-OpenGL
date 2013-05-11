//
//  main.m
//  CCgl
//
//  Created by ricky on 13-5-10.
//  Copyright (c) 2013年 ricky. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "cocoagl.h"

#if defined(_WIN32)

#include "glut/glut.h"

#elif defined(__APPLE__)

#include <GLUT/glut.h>

#endif

int _winW = 800, _winH = 600;

const double fovy = 45.0, zNear = 0.5, zFar = 10.0;

void init()
{
    glClearDepth(1.0);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    ccGLEnable(GLSwitchDepthTest);
    ccGLEnable(GLSwitchLighting);
    
    static GLfloat ambient_light[] = {1.0, 1.0, 1.0, 1.0};
    static GLfloat diffuse_light[] = {0.8, 0.8, 1.0, 1.0};
    static GLfloat light_pos[] = {0.0, 2.0, 5.0, 1.0};
    static GLfloat light_direction[] = {0.0, 0.0,-1.0};
    
    ccGLLight(GLLight0, GLLightParamAmbientfv4, ambient_light);
    ccGLLight(GLLight0, GLLightParamDiffusefv4, diffuse_light);
    ccGLLight(GLLight0, GLLightParamPositionfv4, light_pos);
    ccGLLight(GLLight0, GLLightParamSpotCutofff, 30.0);
    ccGLLight(GLLight0, GLLightParamSpotDirectionfv3, light_direction);
}

void onDraw()
{
    ccGLClear(GLAttribMaskDepthAndColorBuffer);
    
    ccGLMatrixMode(GLMatrixModeModelView);
    glLoadIdentity();
    
    gluLookAt(0, 0, 4, 0, 0, 0, 0, 1, 0);
    
    static GLfloat ambient_light[] = {0.9, 0.9, 0.9, 0.9};
    static GLfloat diffuse_light[] = {0.8, 0.8, 0.8, 0.8};
    
    ccGLMaterial(GLFaceFront, GLLightParamAmbientfv4, ambient_light);
    ccGLMaterial(GLFaceFront, GLLightParamDiffusefv4, diffuse_light);
    
    glutSolidTeapot(1.0);
    
    glutSwapBuffers();
}

void onResize(int w, int h)
{
    _winW = w, _winH = h;
    
    ccGLMatrixMode(GLMatrixModeProjection);
    glLoadIdentity();
    gluPerspective(fovy, (double)_winW / _winH, zNear, zFar);
    
    ccGLMatrixMode(GLMatrixModeModelView);
    glViewport(0, 0, _winW, _winH);
}

void onKeyborad(unsigned char key, int x, int y)
{
    switch (key) {
        case 27:
            exit(0);
            break;
            
        default:
            break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(_winW, _winH);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    
    glutCreateWindow("Test cocoaGL");
    glutDisplayFunc(onDraw);
    glutReshapeFunc(onResize);
    glutKeyboardFunc(onKeyborad);
    
    init();
    
    glutMainLoop();
    
    return 0;
}
