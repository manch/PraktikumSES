#ifndef _GF3D_H_INCLUDED
#define _GF3D_H_INCLUDED

#ifndef _GLES_EGL_H_INCLUDED
#include "../GLES/egl.h"
#endif

#ifndef _GF_H_INCLUDED
#include "./gf.h"
#endif

__BEGIN_DECLS

typedef struct _gf_3d_target *		gf_3d_target_t;

#ifndef _WIN32
#include <_pack1.h>
#endif

typedef struct {
	gf_format_t	format;
	_uint32		create_flags;
} gf_3d_config_info_t;

#ifndef _WIN32
#include <_packpop.h>
#endif

extern int gf_3d_target_create(gf_3d_target_t *ptarget, gf_layer_t layer,
    gf_surface_t *surfaces, int nsurfaces, int width, int height, gf_format_t format);
extern void gf_3d_target_free(gf_3d_target_t target);
extern int gf_3d_query_config(gf_3d_config_info_t *info, gf_dev_t dev,
    EGLDisplay display, EGLConfig cfg);
extern int gf_context_set_surface_3d(gf_context_t context, EGLSurface surface);

__END_DECLS

#endif  /* _GF3D_H_INCLUDED */
