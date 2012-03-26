#ifndef GRAPHICSINCLUDES_H_
#define GRAPHICSINCLUDES_H_

#ifdef __QNX__
#ifdef EGL
#include <GLES/gl.h>
#include <GLES/glext.h>
#include <GLES/egl.h>
#include <gf/gf3d.h>
#include "CGraphicsDriverEGL.h"
#elif GFX
#include "gfx.h"
#include <GLES/glext.h>
#include "CGraphicsDriverGFX.h"
#endif
#elif __linux__
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glx.h>
#include "CGraphicsDriverGLUT.h"
#elif __APPLE__
#include <GLUT/glut.h>
#include "CGraphicsDriverGLUT.h"
#endif


#endif /* GRAPHICSINCLUDES_H_ */
