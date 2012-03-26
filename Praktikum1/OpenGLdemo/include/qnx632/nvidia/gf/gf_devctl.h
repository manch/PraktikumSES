#ifndef _GF_DEVCTL_H_INCLUDED
#define _GF_DEVCTL_H_INCLUDED

#include "./gf.h"

/* driver devctl command manifests for gf_devctl() */
enum {
	GF_DEVCTL_STATS = 1, /* for used with devg-stats module */
	/* Driver specific devctl's start at 0x100 */
};

/* driver devctl command manifests for gf_display_devctl() */
typedef enum {
	GF_DISPLAY_DEVCTL_SET_SYNC_SOURCE = 1,
	GF_DISPLAY_DEVCTL_UPDATE_DISPLAY_SETTINGS
} gf_display_devctl_t;

__BEGIN_DECLS

extern int gf_devctl(gf_dev_t gdev, int cmd, void *data_in, 
    int nbytes, void *data_out, int *out_buffer_size);
extern int gf_display_devctl(gf_display_t display, gf_display_devctl_t cmd,
    void *data_in, int nbytes, void *data_out, int *out_buffer_size);

__END_DECLS
	
#endif
