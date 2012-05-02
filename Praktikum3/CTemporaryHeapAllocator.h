/*
 * CTemporaryHeapAllocator.h
 *
 *  Created on: 25.04.2012
 *      Author: istchmanu
 */

#ifndef CTEMPORARYHEAPALLOCATOR_H_
#define CTEMPORARYHEAPALLOCATOR_H_

#include "IAllocator.h"

class CTemporaryHeapAllocator: public IAllocator {
public:
	CTemporaryHeapAllocator(size_t heapSize);
	CTemporaryHeapAllocator(char * memPtr, size_t heapSize);
	virtual ~CTemporaryHeapAllocator();
	void reset(){
		mBytesAllocated = 0;
	}
	void *allocate(size_t memSize);
	void deallocate(void * memPtr);
	void * operator new(size_t size);

private:
	char * mHeapMemoryPtr;
	size_t mHeapSizeInBytes;
	size_t mBytesAllocated;
	bool mDeleteMemNeeded;
};

#endif /* CTEMPORARYHEAPALLOCATOR_H_ */
