/*
 * StaticMem.h
 *
 *  Created on: 16.04.2012
 *      Author: istchmanu
 */
#ifndef STATICMEM_H_
#define STATICMEM_H_

#include <cstdlib>
#include <iostream.h>
#include <stdlib.h>
#include <stdint.h>
using namespace std;

#define MemSize 10000
#define MAKE_ALIGMENT_SIZE(size) ((((size)+(sizeof(INT32_MAX)-1))/sizeof(INT32_MAX))*sizeof(INT32_MAX))



class StaticMem {
public:
	StaticMem();
	char * getStaticMem(size_t size);
private:
	static char mem[MemSize];
	static char * sCurrentPtr;// = mem;
	static char * endPtr;// = mem + MemSize;
};

#endif /* STATICMEM_H_ */

