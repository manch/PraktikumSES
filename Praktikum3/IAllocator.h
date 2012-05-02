/*
 * IAllocator.h
 *
 *  Created on: 23.04.2012
 *      Author: istchmanu
 */

#ifndef IALLOCATOR_H_
#define IALLOCATOR_H_
#include <cstdlib>
#include <iostream.h>
#include <stdlib.h>
#include <stdint.h>
#include "FWMemory.h"

using namespace std;


class IAllocator {
public:
	virtual void *allocate(size_t memSize)=0;
	virtual void deallocate(void * memPtr)=0;

	IAllocator();
	virtual ~IAllocator();
};

#endif /* IALLOCATOR_H_ */
