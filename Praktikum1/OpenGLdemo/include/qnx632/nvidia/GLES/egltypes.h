#ifndef EGLTYPES_H
#define EGLTYPES_H


#ifdef __cplusplus
extern "C" {
#endif

#ifndef APIENTRY
#ifdef _WIN32
#define WINAPI __stdcall
#define APIENTRY WINAPI
#else
#define APIENTRY 
#endif
#endif
    
/*
** Types and resources
*/
typedef int EGLBoolean;
typedef int EGLint;
typedef int EGLenum;
typedef void *EGLClientBuffer;
typedef struct NvEglOpaqueDisplay *EGLDisplay;
typedef struct NvEglOpaqueConfig  *EGLConfig;
typedef struct NvEglOpaqueSurface *EGLSurface;
typedef struct NvEglOpaqueContext *EGLContext;
typedef struct NvEglOpaquePerfMonitor *EGLPerfMonitorNV;
typedef struct NvEglOpaquePerfCounter *EGLPerfCounterNV;
typedef struct NvEglOpaquePerfMarker  *EGLPerfMarkerNV;

typedef void *EGLClientBufferOES;
typedef struct nvEglOpaqueImage *EGLImageOES;

/*
** EGL and native handle values
*/
#define EGL_DEFAULT_DISPLAY ((NativeDisplayType)0)
#define EGL_NO_CONTEXT ((EGLContext)0)
#define EGL_NO_DISPLAY ((EGLDisplay)0)
#define EGL_NO_SURFACE ((EGLSurface)0)
#define EGL_NO_PERFMONITOR_NV ((EGLPerfMonitorNV)0)
#define EGL_DEFAULT_PERFMARKER_NV ((EGLPerfMarkerNV)0)

#define EGL_NO_IMAGE ((EGLImageOES)0)

/*
 * Native window system types
 */
#ifdef _WIN32
    #undef  WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
    #ifdef __cplusplus
        }
        #include <windows.h>
        extern "C" {
    #else
        #include <windows.h>
    #endif
#endif

#ifdef _WIN32_WCE
    typedef int NativeDisplayType;
    typedef HWND NativeWindowType;
    typedef HDC NativePixmapType;
#elif (defined(WINSYS_GF) && (defined(__QNX__) || defined(__QNXNTO__)))
    // Eventually, the "defined(WINSYS_GF)" part of this will be removed
    //   and GF will be the default for QNX systems.
    // For now, while GF support is still under development, we default to
    //   NEWS when using QNX so that existing programs still work.
    typedef void* NativeDisplayType;
    typedef void* NativeWindowType;
    typedef void* NativePixmapType;
#else
    typedef struct NEWSDisplayOpaque  *NativeDisplayType;
    typedef struct NEWSDrawableOpaque *NativePixmapType;
    typedef struct NEWSDrawableOpaque *NativeWindowType;
#endif

#ifdef _WIN32
    typedef signed __int64 EGLint64NV;
    typedef unsigned __int64 EGLuint64NV;
#else
    typedef signed long long EGLint64NV;
    typedef unsigned long long EGLuint64NV;
#endif
          
#ifdef __cplusplus
}
#endif

#endif /* EGLTYPES_H */
