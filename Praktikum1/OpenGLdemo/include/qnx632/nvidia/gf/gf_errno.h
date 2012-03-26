#ifndef _GF_ERRNO_H_INCLUDED
#define _GF_ERRNO_H_INCLUDED

#define GF_ERR_OK			0x00000000	/* no error */
#define GF_ERR_MEM			0x00000001	/* memory allocation error */
#define GF_ERR_IODISPLAY	0x00000002	/* error accessing io-display */
#define GF_ERR_DEVICE		0x00000003	/* error accessing device */
#define GF_ERR_SHMEM		0x00000004	/* error accessing shared memory */
#define GF_ERR_DLL			0x00000005	/* error accessing dll/entrypoints */
#define GF_ERR_THREAD		0x00000006	/* thread registration failure */
#define GF_ERR_PARM			0x00000007	/* invalid parameter */
#define GF_ERR_INUSE		0x00000008	/* resource in use */
#define GF_ERR_NOSUPPORT	0x00000009	/* unsupported operation */
#define GF_ERR_CFG			0x0000000a	/* bad configuration */
#define GF_ERR_NOLOCK		0x0000000b	/* h/w not locked */
#define GF_ERR_IO			0x0000000c	/* h/w level I/O error */
#define GF_ERR_DEADLOCK		0x0000000d	/* h/w locked; deadlock avoided */
#define GF_ERR_SURFDESTROYED	0x0000000e	/* target surface destroyed, due to modeswitch or power management */

#endif
