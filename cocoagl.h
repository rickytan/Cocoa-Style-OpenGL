
#ifndef COCOA_GL
#define COCOA_GL

#include <gl/glew.h>		// Header File For The OpenGL Extension Library
#include <gl/gl.h>			// Header File For The OpenGL32 Library
#include <gl/glu.h>			// Header File For The GLu32 Library
#include <gl/glaux.h>		// Header File For The Glaux Library

#ifndef CC_ENUM
#define CC_ENUM(_type, _name) typedef enum _name _name; enum _name : _type
#endif


#ifdef __cplusplus
//extern "C" {
#endif



typedef struct GLPoint {
	GLfloat x, y;
} GLPoint;

typedef struct GLSize {
	GLfloat width, height;
} GLSize;

typedef struct GLRect {
	GLPoint origin;
	GLSize size;
} GLRect;


CC_ENUM(int, GLSwitch) {
	GLSwitchDepthTest = GL_DEPTH_TEST,
	GLSwitchAlphaTest = GL_ALPHA_TEST,
	GLSwitchLighting = GL_LIGHTING,
	GLSwitchNormalize = GL_NORMALIZE,
	GLSwitchCullFace = GL_CULL_FACE,
	GLSwitchBlend = GL_BLEND,
	GLSwitchLineStipple = GL_LINE_STIPPLE,
};

inline void ccglEnable(GLSwitch type)
{
	glEnable(type);
}

inline void ccglTurnOn(GLSwitch type)
{
	glEnable(type);
}

inline void ccglDisable(GLSwitch type)
{
	glDisable(type);
}

inline void ccglTurnOff(GLSwitch type)
{
	glDisable(type);
}

inline GLboolean ccglIsEnabled(GLSwitch type)
{
	return glIsEnabled(type);
}

CC_ENUM(int, GLDrawMode) {
	GLDrawModePoints =  GL_POINTS,
	GLDrawModeLines = GL_LINES,
	GLDrawModeLineLoop = GL_LINE_LOOP,
	GLDrawModeLineStrip = GL_LINE_STRIP,
	GLDrawModeTriangles = GL_TRIANGLES,
	GLDrawModeTriangleStrip = GL_TRIANGLE_STRIP,
	GLDrawModeTriangleFan = GL_TRIANGLE_FAN,
	GLDrawModeQuads = GL_QUADS,
	GLDrawModeQuadStrip = GL_QUAD_STRIP,
	GLDrawModePolygon = GL_POLYGON,
};

inline void ccglBegin(GLDrawMode mode)
{
	glBegin(mode);
}

inline void ccglEnd()
{
	glEnd();
}

CC_ENUM(int, GLLight) {
	GLLight0 = GL_LIGHT0,
	GLLight1 = GL_LIGHT1,
	GLLight2 = GL_LIGHT2,
	GLLight3 = GL_LIGHT3,
	GLLight4 = GL_LIGHT4,
	GLLight5 = GL_LIGHT5,
	GLLight6 = GL_LIGHT6,
	GLLight7 = GL_LIGHT7,
};

CC_ENUM(int, GLLightModel) {
	GLLightModelLocalViewerf = GL_LIGHT_MODEL_LOCAL_VIEWER,
	GLLightModelTwoSidef = GL_LIGHT_MODEL_TWO_SIDE,
	GLLightModelAmbientfv3 = GL_LIGHT_MODEL_AMBIENT,
};

CC_ENUM(int, GLLightParam) {
	GLLightParamAmbientfv4 = GL_AMBIENT,
	GLLightParamDiffusefv4 = GL_DIFFUSE,
	GLLightParamSpecularfv4 = GL_SPECULAR,
	GLLightParamPositionfv4 = GL_POSITION,
	GLLightParamSpotDirectionfv3 = GL_SPOT_DIRECTION,
	GLLightParamSpotExponentf = GL_SPOT_EXPONENT,
	GLLightParamSpotCutofff = GL_SPOT_CUTOFF,
	GLLightParamConstantAttenuationf = GL_CONSTANT_ATTENUATION,
	GLLightParamLinearAttenuationf = GL_LINEAR_ATTENUATION,
	GLLightParamQuadraticAttenuationf = GL_QUADRATIC_ATTENUATION,
};

inline static void ccglLight(GLLight light, GLLightParam param, GLfloat value)
{
	glLightf(light, param, value);
}

inline static void ccglLight(GLLight light, GLLightParam param, const GLfloat *value)
{
	glLightfv(light, param, value);
}

inline void ccglLightModel(GLLightModel model, GLfloat value)
{
	glLightModelf(model, value);
}

inline void ccglLightModel(GLLightModel model, const GLfloat *value)
{
	glLightModelfv(model, value);
}

CC_ENUM(int, GLUnsignedType) {
	GLUnsignedTypeByte = GL_UNSIGNED_BYTE,
	GLUnsignedTypeShort = GL_UNSIGNED_SHORT,
	GLUnsignedTypeInt = GL_UNSIGNED_INT,
};



CC_ENUM(int, GLSignedType) {
	GLSignedTypeByte = GL_BYTE,
	GLSignedTypeShort = GL_SHORT,
	GLSignedTypeInt = GL_INT,
	GLSignedTypeFloat = GL_FLOAT,
	GLSignedTypeDouble = GL_DOUBLE,
};

CC_ENUM(int, GLDecimalType) {
	GLDecimalTypeFloat = GL_FLOAT,
	GLDecimalTypeDouble = GL_DOUBLE,
};

CC_ENUM(int, GLType) {
	GLTypeByte = GL_BYTE,
	GLTypeUnsignedByte = GL_UNSIGNED_BYTE,
	GLTypeShort = GL_SHORT,
	GLTypeUnsignedShort = GL_UNSIGNED_SHORT,
	GLTypeInt = GL_INT,
	GLTypeUnsignedInt = GL_UNSIGNED_INT,
	GLTypeFloat = GL_FLOAT,
	GLType2Bytes = GL_2_BYTES,
	GLType3Bytes = GL_3_BYTES,
	GLType4Bytes = GL_4_BYTES,
	GLTypeDouble = GL_DOUBLE,
};

CC_ENUM(int, GLVertexType) {
	GLVertexTypeShort = GL_SHORT,
	GLVertexTypeInt = GL_INT,
	GLVertexTypeFloat = GL_FLOAT,
	GLVertexTypeDouble = GL_DOUBLE,
};

CC_ENUM(int, GLColorType) {
	GLColorTypeByte = GL_BYTE,
	GLColorTypeUnsignedByte = GL_UNSIGNED_BYTE,
	GLColorTypeShort = GL_SHORT,
	GLColorTypeUnsignedShort = GL_UNSIGNED_SHORT,
	GLColorTypeInt = GL_INT,
	GLColorTypeUnsignedInt = GL_UNSIGNED_INT,
	GLColorTypeFloat = GL_FLOAT,
	GLColorTypeDouble = GL_DOUBLE,
};

inline void ccglVertexPointer(GLint size_2or3or4, GLVertexType type, GLsizei stride, const GLvoid *pointer)
{
	glVertexPointer(size_2or3or4, type, stride, pointer);
}

inline void ccglColorPointer(GLint size_3or4, GLColorType type, GLsizei stride, const GLvoid *pointer)
{
	glColorPointer(size_3or4, type, stride, pointer);
}

inline void ccglSecondaryColorPointer(GLColorType type, GLsizei stride, const GLvoid *pointer)
{
	glSecondaryColorPointer(3, type, stride, pointer);
}

inline void ccglNormalPointer(GLSignedType type, GLsizei stride, const GLvoid *pointer)
{
	glNormalPointer(type, stride, pointer);
}

inline void ccglFogCoordPointer(GLDecimalType type, GLsizei stride, const GLvoid *pointer)
{
	glFogCoordPointer(type, stride, pointer);
}

inline void ccglTexCoordPointer(GLint size_1or2or3or4, GLVertexType type, GLsizei stride, const GLvoid *pointer)
{
	glTexCoordPointer(size_1or2or3or4, type, stride, pointer);
}

inline void ccglEdgeFlagPointer(GLsizei stride, const GLvoid *pointer)
{
	glEdgeFlagPointer(stride, pointer);
}

inline void ccglDrawElements(GLDrawMode mode, GLsizei count, GLUnsignedType type, const GLvoid *indices)
{
	glDrawElements(mode, count, type, indices);
}

CC_ENUM(int, GLFaceDirection) {
	GLFaceDirectionCounterClockWiseIsFront = GL_CCW,
	GLFaceDirectionClockWiseIsFront = GL_CW,
};

inline void ccglFrontFace(GLFaceDirection direction)
{
	glFrontFace(direction);
}

CC_ENUM(int, GLFace) {
	GLFaceFront = GL_FRONT,
	GLFaceBack = GL_BACK,
	GLFaceFrontAndBack = GL_FRONT_AND_BACK,
};

inline void ccglCullFace(GLFace face)
{
	glCullFace(face);
}

inline void ccglMaterial(GLFace face, GLLightParam param, GLfloat value)
{
	glMaterialf(face, param, value);
}

inline void ccglMaterial(GLFace face, GLLightParam param, const GLfloat *value)
{
	glMaterialfv(face, param, value);
}

CC_ENUM(int, GLPolygonMode) {
	GLPolygonModePoint = GL_POINT,
	GLPolygonModeLine = GL_LINE,
	GLPolygonModeFill = GL_FILL,
};

inline void ccglPolygonMode(GLFace face, GLPolygonMode mode)
{
	glPolygonMode(face, mode);
}

CC_ENUM(int, GLMatrixMode) {
	GLMatrixModeProjection = GL_PROJECTION,
	GLMatrixModeModelView = GL_MODELVIEW,
	GLMatrixModeTexture = GL_TEXTURE,
};

inline void ccglMatrixMode(GLMatrixMode mode)
{
	glMatrixMode(mode);
}

CC_ENUM(int, GLShadeModel) {
	GLShadeModelFlat = GL_FLAT,
	GLShadeModelSmooth = GL_SMOOTH,
};

inline void ccglShadeModel(GLShadeModel model)
{
	glShadeModel(model);
}

#ifdef __cplusplus
//};
#endif

#endif