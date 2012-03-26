#ifndef GFX_H_INCLUDED
#define GFX_H_INCLUDED

#include "./GLES/egl.h"
#include "./GLES/gl.h"

typedef struct GfxColorRec 
{
    unsigned int   r;
    unsigned int   g;
    unsigned int   b;
    unsigned int   a;
} GfxColor;

typedef struct GfxStateRec 
{
    EGLDisplay        display;
    EGLSurface        window;
    EGLConfig         config;
    EGLContext        context;
    EGLint            width;
    EGLint            height;
    NativeDisplayType nativeDisplay;
    NativeWindowType  nativeWindow;
    int               frameLimit;
    int               stencilBuffer;
    char *            screenshotPrefix;
    GfxColor          color;
    void *            gfxVariantData;
    unsigned int      frameCounter;
    int               noSwapBuffers;
} GfxEglState;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Creates a OpenGLES drawable window. Don't call any gl functions before this
 * function successfully returned.
 */ 
int GfxEglInitialize(GfxEglState *pGfxEglState);
/**
 * Destroys the window. Don't call any gl functions after a call to this function.
 */
void GfxEglShutdown(GfxEglState *pGfxEglState, char *msg);
/**
 * Sets the swap interval to the parameter given.
 */
void GfxEglSwapInterval(GfxEglState *pGfxEglState, int interval);
/**
 * Swap the gl buffers. Don't call eglSwapBuffers directly.
 */
void GfxEglSwapBuffers(GfxEglState *pGfxEglState);

/**
 * Returns true if Ctrl-C was hit.
 */
int GfxAppAlive(void);

/**
 * Sets a maximum number of frames the application is allowed to throw out.
 */
void GfxSetFrameLimit(GfxEglState *pGfxEglState, int fLim);

/**
 * Set requestStencil to true before you call GfxEglInitialize to have a stencil
 * buffer.
 */
void GfxSetStencilBuffer(GfxEglState *pGfxEglState, int requestStencil);

/**
 * Makes a screen shot.
 */
void GfxMakeScreenshot(GfxEglState *pGfxEglState, GLenum format, char * fileName);

/**
 * Makes a screen shot named "screenshotNNNNN.$fileExt". NNNNN is incremented by one every
 * time you call this function.
 */
void GfxMakeSeriesScreenshot(GfxEglState *pGfxEglState, GLenum format, char * fileExt);

/**
 * Decodes the last GL error into a readable format 
 */
void GfxGlDecodeError(void);

/**
 * Decodes the last EGL error into a readable format 
 */
void GfxEglDecodeError(void);

/**
 * Sets the color for the next drawing operation
 */
void GfxSetColor(GfxEglState *pGfxEglState, float r, float g, float b);

/**
 * Draws a rectangle with the set color to the screen
 */
void GfxDrawRect(GfxEglState *pGfxEglState, int x1, int y1, int x2, int y2);


float getRealTime(void);
float getCpuTime(void);

//Call this to start a CPU load measurement
void startCpuTimeMeasure(void);
//Call this to stop a CPU load measurement and get a
//value between 0..100 representing the systems CPU-load 
//since the last call to startCpuTimeMeasure
float stopCpuTimeMeasure(void);


void glesuLookAtx(GLfixed eyex,    GLfixed eyey,    GLfixed eyez,
                  GLfixed centerx, GLfixed centery, GLfixed centerz,
                  GLfixed upx,     GLfixed upy,     GLfixed upz);
void glesuPerspectivex(GLfixed fovy, GLfixed aspect, GLfixed zNear, GLfixed zFar);
#ifndef COMMON_LITE
void glesuLookAt(GLfloat eyex,    GLfloat eyey,    GLfloat eyez,
                 GLfloat centerx, GLfloat centery, GLfloat centerz,
                 GLfloat upx,     GLfloat upy,     GLfloat upz);
void glesuPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar);
#endif

void init_keyboard(int _fd);
void close_keyboard(void);
int kbhit(void);
int readch(void);

#ifdef __cplusplus
}
#endif

#endif
