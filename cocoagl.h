
#ifndef __COCOA_GL__
#define __COCOA_GL__

#include <stdio.h>

#ifdef _WIN32
#include <gl/glew.h>		// Header File For The OpenGL Extension Library
#include <gl/gl.h>			// Header File For The OpenGL32 Library
#include <gl/glu.h>			// Header File For The GLu32 Library
#include <gl/glaux.h>		// Header File For The Glaux Library
#elif defined(__MACOS__) ||  defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
//#include <OpenGL/glext.h>
#endif

#ifndef CC_ENUM
#ifdef _WIN32
#define CC_ENUM(_type, _name) typedef enum _name _name; enum _name : _type
#elif defined(__MACOS__) || defined(__APPLE__)
#define CC_ENUM(_type, _name) typedef enum _name : _type _name; enum _name : _type
#endif
#endif


#ifdef __cplusplus
extern "C" {
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
    
typedef struct GLVar {
    union {
        GLbyte charValue;
        GLubyte ucharValue;
        GLshort shortValue;
        GLushort ushortValue;
        GLint intValue;
        GLuint uintValue;
        GLfloat floatValue;
        GLdouble doubleValue;
        GLvoid *pointerValue;
        const GLvoid *cpointerValue;
    } data;

    GLVar() { data.intValue = 0;}
    GLVar(GLbyte b) { data.charValue = b;}
    GLVar(GLubyte u) { data.ucharValue = u;}
    GLVar(GLint i) { data.intValue = i;}
    GLVar(GLuint u) { data.uintValue = u;}
    GLVar(GLshort s) { data.shortValue = s;}
    GLVar(GLushort s) { data.ushortValue = s;}
    GLVar(GLfloat f) { data.floatValue = f;}
    GLVar(GLdouble d) { data.doubleValue = d;}
    GLVar(const GLvoid *p) { data.cpointerValue = p;}
    GLVar(GLvoid *p) { data.pointerValue = p;}
    GLbyte getChar() { return data.charValue;}
    GLubyte getUchar() { return data.ucharValue;}
    GLshort getShort() { return data.shortValue;}
    GLushort getUshort() { return data.ushortValue;}
    GLint getInt() { return data.intValue;}
    GLuint getUint() { return data.uintValue;}
    GLfloat getFloat() { return data.floatValue;}
    GLdouble getDouble() { return data.doubleValue;}
    const GLvoid* getPointer() const{ return data.cpointerValue;}
    GLvoid* getPointer() { return data.pointerValue;}
    
} GLVar;


CC_ENUM(int, GLSwitch) {
    /*      GL_FOG */
    /*      GL_LIGHTING */
    /*      GL_TEXTURE_1D */
    /*      GL_TEXTURE_2D */
    /*      GL_LINE_STIPPLE */
    /*      GL_POLYGON_STIPPLE */
    /*      GL_CULL_FACE */
    /*      GL_ALPHA_TEST */
    /*      GL_BLEND */
    /*      GL_INDEX_LOGIC_OP */
    /*      GL_COLOR_LOGIC_OP */
    /*      GL_DITHER */
    GLSwitchStencilTest = GL_STENCIL_TEST,
    /*      GL_DEPTH_TEST */
    /*      GL_CLIP_PLANE0 */
    /*      GL_CLIP_PLANE1 */
    /*      GL_CLIP_PLANE2 */
    /*      GL_CLIP_PLANE3 */
    /*      GL_CLIP_PLANE4 */
    /*      GL_CLIP_PLANE5 */
    /*      GL_LIGHT0 */
    /*      GL_LIGHT1 */
    /*      GL_LIGHT2 */
    /*      GL_LIGHT3 */
    /*      GL_LIGHT4 */
    /*      GL_LIGHT5 */
    /*      GL_LIGHT6 */
    /*      GL_LIGHT7 */
    /*      GL_TEXTURE_GEN_S */
    /*      GL_TEXTURE_GEN_T */
    /*      GL_TEXTURE_GEN_R */
    /*      GL_TEXTURE_GEN_Q */
    /*      GL_MAP1_VERTEX_3 */
    /*      GL_MAP1_VERTEX_4 */
    /*      GL_MAP1_COLOR_4 */
    /*      GL_MAP1_INDEX */
    /*      GL_MAP1_NORMAL */
    /*      GL_MAP1_TEXTURE_COORD_1 */
    /*      GL_MAP1_TEXTURE_COORD_2 */
    /*      GL_MAP1_TEXTURE_COORD_3 */
    /*      GL_MAP1_TEXTURE_COORD_4 */
    /*      GL_MAP2_VERTEX_3 */
    /*      GL_MAP2_VERTEX_4 */
    /*      GL_MAP2_COLOR_4 */
    /*      GL_MAP2_INDEX */
    /*      GL_MAP2_NORMAL */
    /*      GL_MAP2_TEXTURE_COORD_1 */
    /*      GL_MAP2_TEXTURE_COORD_2 */
    /*      GL_MAP2_TEXTURE_COORD_3 */
    /*      GL_MAP2_TEXTURE_COORD_4 */
    GLSwitchPointSmooth = GL_POINT_SMOOTH,
    GLSwitchLineSmooth = GL_LINE_SMOOTH,
    /*      GL_POLYGON_SMOOTH */
    /*      GL_SCISSOR_TEST */
    /*      GL_COLOR_MATERIAL */
    GLSwitchNormalize = GL_NORMALIZE,
    /*      GL_AUTO_NORMAL */
    GLClientSwitchVertexArray = GL_VERTEX_ARRAY,
    /*      GL_NORMAL_ARRAY */
    /*      GL_COLOR_ARRAY */
    /*      GL_INDEX_ARRAY */
    /*      GL_TEXTURE_COORD_ARRAY */
    /*      GL_EDGE_FLAG_ARRAY */
    /*      GL_POLYGON_OFFSET_POINT */
    /*      GL_POLYGON_OFFSET_LINE */
    /*      GL_POLYGON_OFFSET_FILL */
    /*      GL_COLOR_TABLE */
    /*      GL_POST_CONVOLUTION_COLOR_TABLE */
    /*      GL_POST_COLOR_MATRIX_COLOR_TABLE */
    /*      GL_CONVOLUTION_1D */
    /*      GL_CONVOLUTION_2D */
    GLSwitchSeparable2D = GL_SEPARABLE_2D,
    GLSwitchHistogram = GL_HISTOGRAM,
    GLSwitchMinMax = GL_MINMAX,
    GLSwitchRescaleNormal = GL_RESCALE_NORMAL,
    GLSwitchTexture3D = GL_TEXTURE_3D,
	GLSwitchDepthTest = GL_DEPTH_TEST,
	GLSwitchAlphaTest = GL_ALPHA_TEST,
	GLSwitchLighting = GL_LIGHTING,
	GLSwitchCullFace = GL_CULL_FACE,
	GLSwitchBlend = GL_BLEND,
	GLSwitchLineStipple = GL_LINE_STIPPLE,
};

inline void ccGLEnable(GLSwitch type)
{
	glEnable(type);
}

inline void ccGLTurnOn(GLSwitch type)
{
	glEnable(type);
}

inline void ccGLDisable(GLSwitch type)
{
	glDisable(type);
}

inline void ccGLTurnOff(GLSwitch type)
{
	glDisable(type);
}

inline GLboolean ccGLIsEnabled(GLSwitch type)
{
	return glIsEnabled(type);
}
    
    CC_ENUM(int, GLAttribMask) {
        GLAttribMaskCurrent = GL_CURRENT_BIT,
        GLAttribMaskPoint = GL_POINT_BIT,
        GLAttribMaskLine = GL_LINE_BIT,
        GLAttribMaskPolygon = GL_POLYGON_BIT,
        GLAttribMaskPolygonStipple = GL_POLYGON_STIPPLE_BIT,
        GLAttribMaskPixelMode = GL_PIXEL_MODE_BIT,
        GLAttribMaskLighting = GL_LIGHTING_BIT,
        GLAttribMaskFog = GL_FOG_BIT,
        GLAttribMaskDepthBuffer = GL_DEPTH_BUFFER_BIT,
        GLAttribMaskAccumBuffer = GL_ACCUM_BUFFER_BIT,
        GLAttribMaskStencilBuffer = GL_STENCIL_BUFFER_BIT,
        GLAttribMaskViewport = GL_VIEWPORT_BIT,
        GLAttribMaskTransform = GL_TRANSFORM_BIT,
        GLAttribMaskEnable = GL_ENABLE_BIT,
        GLAttribMaskColorBuffer = GL_COLOR_BUFFER_BIT,
        GLAttribMaskHint = GL_HINT_BIT,
        GLAttribMaskEval = GL_EVAL_BIT,
        GLAttribMaskList = GL_LIST_BIT,
        GLAttribMaskTexture = GL_TEXTURE_BIT,
        GLAttribMaskScissor = GL_SCISSOR_BIT,
        GLAttribMaskAllAttrib = GL_ALL_ATTRIB_BITS,
        GLAttribMaskDepthAndColorBuffer = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT,
        GLAttribMaskAllBuffer = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_ACCUM_BUFFER_BIT,
    };

inline void ccGLClear(GLAttribMask mask)
{
    glClear(mask);
}
    
    /* ReadBufferMode */
    /*      GL_FRONT_LEFT */
    /*      GL_FRONT_RIGHT */
    /*      GL_BACK_LEFT */
    /*      GL_BACK_RIGHT */
    /*      GL_FRONT */
    /*      GL_BACK */
    /*      GL_LEFT */
    /*      GL_RIGHT */
    /*      GL_AUX0 */
    /*      GL_AUX1 */
    /*      GL_AUX2 */
    /*      GL_AUX3 */

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

inline void ccGLBegin(GLDrawMode mode)
{
	glBegin(mode);
}

inline void ccGLEnd()
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

inline static void ccGLLight(GLLight light, GLLightParam param, GLVar value)
{
    switch (param) {
        case GLLightParamAmbientfv4:
        case GLLightParamDiffusefv4:
        case GLLightParamPositionfv4:
        case GLLightParamSpecularfv4:
        case GLLightParamSpotDirectionfv3:
            glLightfv(light, param, (const GLfloat*)value.getPointer());
            break;
        default:
            glLightf(light, param, value.getFloat());
            break;
    }
}

inline void ccGLLightModel(GLLightModel model, GLVar value)
{
    switch (model) {
        case GLLightModelAmbientfv3:
            glLightModelfv(model, (const GLfloat*)value.getPointer());
            break;
        default:
            glLightModelf(model, value.getFloat());
            break;
    }
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

inline void ccGLVertexPointer(GLint size_2or3or4, GLVertexType type, GLsizei stride, const GLvoid *pointer)
{
	glVertexPointer(size_2or3or4, type, stride, pointer);
}

inline void ccGLColorPointer(GLint size_3or4, GLColorType type, GLsizei stride, const GLvoid *pointer)
{
	glColorPointer(size_3or4, type, stride, pointer);
}

inline void ccGLSecondaryColorPointer(GLColorType type, GLsizei stride, const GLvoid *pointer)
{
	glSecondaryColorPointer(3, type, stride, pointer);
}

inline void ccGLNormalPointer(GLSignedType type, GLsizei stride, const GLvoid *pointer)
{
	glNormalPointer(type, stride, pointer);
}

inline void ccGLFogCoordPointer(GLDecimalType type, GLsizei stride, const GLvoid *pointer)
{
	glFogCoordPointer(type, stride, pointer);
}

inline void ccGLTexCoordPointer(GLint size_1or2or3or4, GLVertexType type, GLsizei stride, const GLvoid *pointer)
{
	glTexCoordPointer(size_1or2or3or4, type, stride, pointer);
}

inline void ccGLEdgeFlagPointer(GLsizei stride, const GLvoid *pointer)
{
	glEdgeFlagPointer(stride, pointer);
}

inline void ccGLDrawElements(GLDrawMode mode, GLsizei count, GLUnsignedType type, const GLvoid *indices)
{
	glDrawElements(mode, count, type, indices);
}

CC_ENUM(int, GLFrontFaceDirection) {
	GLFrontFaceDirectionCounterClockWiseIsFront = GL_CCW,
	GLFrontFaceDirectionClockWiseIsFront = GL_CW,
};

inline void ccGLFrontFace(GLFrontFaceDirection direction)
{
	glFrontFace(direction);
}

CC_ENUM(int, GLFace) {
	GLFaceFront = GL_FRONT,
	GLFaceBack = GL_BACK,
	GLFaceFrontAndBack = GL_FRONT_AND_BACK,
};

inline void ccGLCullFace(GLFace face)
{
	glCullFace(face);
}

inline void ccGLMaterial(GLFace face, GLLightParam param, GLVar value)
{
    switch (param) {
        case GLLightParamAmbientfv4:
        case GLLightParamPositionfv4:
        case GLLightParamDiffusefv4:
        case GLLightParamSpecularfv4:
        case GLLightParamSpotDirectionfv3:
            glMaterialfv(face, param, (const GLfloat*)value.getPointer());
            break;
        default:
            glMaterialf(face, param, value.getFloat());
            break;
    }
}

CC_ENUM(int, GLPolygonMode) {
	GLPolygonModePoint = GL_POINT,
	GLPolygonModeLine = GL_LINE,
	GLPolygonModeFill = GL_FILL,
};

inline void ccGLPolygonMode(GLFace face, GLPolygonMode mode)
{
	glPolygonMode(face, mode);
}

CC_ENUM(int, GLMatrixMode) {
	GLMatrixModeProjection = GL_PROJECTION,
	GLMatrixModeModelView = GL_MODELVIEW,
	GLMatrixModeTexture = GL_TEXTURE,
};

inline void ccGLMatrixMode(GLMatrixMode mode)
{
	glMatrixMode(mode);
}

CC_ENUM(int, GLShadeModel) {
	GLShadeModelFlat = GL_FLAT,
	GLShadeModelSmooth = GL_SMOOTH,
};

inline void ccGLShadeModel(GLShadeModel model)
{
	glShadeModel(model);
}

#ifdef __cplusplus
}
#endif

#endif