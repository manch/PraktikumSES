#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define Int32 int

// simple trace macro - NOT THREADSAFE
#define TRACE(format, args...) \
	{ \
		printf("[%s] >> ", __PRETTY_FUNCTION__); \
		printf(format, ##args); \
		printf("\n"); \
	}

#endif /* GLOBAL_H_ */
