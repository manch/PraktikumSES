

#ifndef GLOBAL_H
#define	GLOBAL_H

typedef signed char     Int8;
typedef unsigned char   UInt8;
typedef signed short    Int16;
typedef unsigned short  UInt16;
typedef signed int      Int32;
typedef unsigned int    UInt32;

#ifdef WINDOWS
typedef unsigned int    size_t;
#endif

#define NULLPTR         0
#define NULLCHAR        0

#define MAKE_ALIGNMENT_SIZE(size) ((( (size) + (sizeof(Int32) - 1) ) \
                                  / sizeof(Int32)) * sizeof(32))

#endif	/* GLOBAL_H */

