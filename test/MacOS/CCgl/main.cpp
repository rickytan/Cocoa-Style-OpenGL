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

GLfloat _rotX = 30.f;
GLfloat _rotY = 45.f;
GLfloat _rotZ = 0.f;

void init()
{
    glClearDepth(1.0f);
    glClearColor(0.3f, 0.3f, 0.3f, 0.3f);
    
    ccGLEnable(GLSwitchDepthTest);
    ccGLEnable(GLSwitchLighting);
    //ccGLEnable(GLSwitchNormalize);
    //ccGLEnable(GLSwitchCullFace);
    glEnable(GL_LIGHT0);
    
    ccGLFrontFace(GLFrontFaceDirectionCounterClockWiseIsFront);
    
    static GLfloat ambient_light[] = {0.6, 0.6, 0.6, 1.0};
    static GLfloat diffuse_light[] = {0.4, 0.4, 1.0, 1.0};
    static GLfloat specular_light[] = {0.3, 0.0, 0.0, 1.0};
    static GLfloat light_pos[] = {1.0, 3.0, 1.0, 0.0};
    
    ccGLLight(GLLight0, GLLightParamAmbientfv4, ambient_light);
    ccGLLight(GLLight0, GLLightParamDiffusefv4, diffuse_light);
    //ccGLLight(GLLight0, GLLightParamSpecularfv4, specular_light);
    ccGLLight(GLLight0, GLLightParamPositionfv4, light_pos);
//    ccGLLight(GLLight0, GLLightParamConstantAttenuationf, 2.0);
//    ccGLLight(GLLight0, GLLightParamLinearAttenuationf, .2);
//    ccGLLight(GLLight0, GLLightParamQuadraticAttenuationf, 2.0);
    
//    ccGLLightModel(GLLightModelAmbientfv3, ambient_light);
}

void onDraw()
{
    ccGLClear(GLAttribMaskDepthAndColorBuffer);
    
    ccGLMatrixMode(GLMatrixModeModelView);
    glLoadIdentity();
    
    static GLfloat ambient_light[] = {0.6, 0.6, 0.6, 0.6};
    static GLfloat diffuse_light[] = {0.6, 0.6, 0.8, 0.8};
    static GLfloat specular_light[] = {0.4, 0.0, 0.0, 1.0};
    
    ccGLMaterial(GLFaceFront, GLLightParamAmbientfv4, ambient_light);
    ccGLMaterial(GLFaceFront, GLLightParamDiffusefv4, diffuse_light);
    //ccGLMaterial(GLFaceFront, GLLightParamSpecularfv4, specular_light);
    
    //ccGLPolygonMode(GLFaceFrontAndBack, GLPolygonModeLine);
    
    glTranslatef(0, 0, -4);
    glRotatef(_rotX, 1.0, 0, 0);
    glRotatef(_rotY, 0, 1.0, 0);
    glRotatef(_rotZ, 0, 0, 1.0);
    
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
        case 'a':
            _rotY -= 5.0;
            break;
        case 'd':
            _rotY += 5.0;
            break;
        case 's':
            _rotX += 5.0;
            break;
        case 'w':
            _rotX -= 5.0;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void onIdle()
{
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(_winW, _winH);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    
    glutCreateWindow("Test cocoaGL");
    glutDisplayFunc(onDraw);
    glutReshapeFunc(onResize);
    glutKeyboardFunc(onKeyborad);
    //glutIdleFunc(onIdle);
    
    init();
    
    glutMainLoop();
    
    return 0;
}
