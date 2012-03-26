#ifndef __egl_ext_h_
#define __egl_ext_h_

#include "./egl.h"

#define EGL_OES_image        1
#define EGL_create_pbuffer_from_client_buffer  1
#define EGL_NV_client_api_nvma                 1
#define EGL_NV_system_time   1
#define EGL_NV_perfmon       1

/* EGL_NV_nvma_output_surface */
#define EGL_NVMA_OUTPUT_SURFACE_NV     0x2

/* EGL_OES_image */
#define EGL_GL_TEXTURE_2D_OES                     0x1
#define EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X_OES    0x3 // starts from 0x3, because 0x2 is EGL_NVMA_OUTPUT_SURFACE_NV
#define EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_X_OES    0x4
#define EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Y_OES    0x5
#define EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_OES    0x6
#define EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Z_OES    0x7
#define EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_OES    0x8
#define EGL_GL_RENDERBUFFER_OES                   0x9
#define EGL_VG_PARENT_IMAGE_OES                   0xa
#define EGL_GL_TEXTURE_RECTANGLE_NV_OES           0xb

/* EGL_NV_perfmon */
#define EGL_PERFMONITOR_HARDWARE_COUNTERS_BIT_NV    0x00000001
#define EGL_PERFMONITOR_OPENGL_ES_API_BIT_NV        0x00000010
#define EGL_PERFMONITOR_OPENVG_API_BIT_NV           0x00000020
#define EGL_PERFMONITOR_OPENGL_ES2_API_BIT_NV       0x00000040
#define EGL_COUNTER_NAME_NV            0x1234
#define EGL_COUNTER_DESCRIPTION_NV     0x1235
#define EGL_IS_HARDWARE_COUNTER_NV     0x1236
#define EGL_COUNTER_MAX_NV             0x1237
#define EGL_COUNTER_VALUE_TYPE_NV      0x1238
#define EGL_RAW_VALUE_NV               0x1239
#define EGL_PERCENTAGE_VALUE_NV        0x1240
#define EGL_BAD_CURRENT_PERFMONITOR_NV 0x1241

/* EGL_NV_texture_rectangle */
#define EGL_TEXTURE_RECTANGLE_NV       0x1248

/*
** Functions
*/
#ifdef __cplusplus
extern "C" {
#endif

GLAPI EGLBoolean APIENTRY eglNvmaOutputSurfacePbufferLock(EGLDisplay display,
                                                          EGLSurface pbuffer);
GLAPI EGLBoolean APIENTRY eglNvmaOutputSurfacePbufferUnlock(EGLDisplay display,
                                                            EGLSurface pbuffer);

GLAPI EGLImageOES APIENTRY eglCreateImage2DOES(EGLContext ctx, EGLenum target,
        EGLint level, EGLClientBufferOES buffer);
GLAPI EGLBoolean APIENTRY eglDestroyImageOES(EGLImageOES image);

#ifdef __cplusplus
}
#endif

#endif /* ___egl_ext_h_ */

