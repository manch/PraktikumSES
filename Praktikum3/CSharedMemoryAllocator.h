/*
 * CSharedMemoryAllocator.h
 *
 *  Created on: 25.04.2012
 *      Author: istchmanu
 */

#ifndef CSHAREDMEMORYALLOCATOR_H_
#define CSHAREDMEMORYALLOCATOR_H_
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

#include "IAllocator.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>


class CSharedMemoryAllocator: public IAllocator {
public:
	static IAllocator * getAllocator();
	CSharedMemoryAllocator();
	virtual ~CSharedMemoryAllocator();
	void *allocate(size_t memSize);
	void deallocate(void * memSize){};

private:
	char * memPtr;
	static IAllocator *sAllocatorPtr;
};

#endif /* CSHAREDMEMORYALLOCATOR_H_ */
