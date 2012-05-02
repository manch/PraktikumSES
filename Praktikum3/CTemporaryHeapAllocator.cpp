/*
 * CTemporaryHeapAllocator.cpp
 *
 *  Created on: 25.04.2012
 *      Author: istchmanu
 */

#include "CTemporaryHeapAllocator.h"

CTemporaryHeapAllocator::CTemporaryHeapAllocator(size_t heapSize)
{
	mHeapMemoryPtr = NEW_DYNAMIC_ARRAY(char, heapSize);
	mHeapSizeInBytes = heapSize;
	mBytesAllocated = 0;
	mDeleteMemNeeded = true;
}

CTemporaryHeapAllocator::CTemporaryHeapAllocator(char * memPtr, size_t heapSize){
	mHeapMemoryPtr = memPtr;
	mHeapSizeInBytes = heapSize;
	mBytesAllocated = 0;
	mDeleteMemNeeded = false;
}


CTemporaryHeapAllocator::~CTemporaryHeapAllocator() {
	// TODO Auto-generated destructor stub
	if(true == mDeleteMemNeeded){
		DELETE_DYNAMIC_ARRAY(mHeapMemoryPtr);
	}
}

void * CTemporaryHeapAllocator::allocate(size_t memSize){
	void * allocatedPtr = mHeapMemoryPtr + mBytesAllocated;
	mBytesAllocated += memSize;
	if(mBytesAllocated <= mHeapSizeInBytes){
		return 0;
	}
	mBytesAllocated = MAKE_ALIGMENT_SIZE(mBytesAllocated);
	return allocatedPtr;
}

void CTemporaryHeapAllocator::deallocate(void * memPtr){};


void * CTemporaryHeapAllocator::operator new (size_t size){

	void *memory=::new CTemporaryHeapAllocator(size);
	if (memory==NULL) {
		cerr << "Leider sind nicht einmal " << size << " Bytes frei!\n";
		exit(0);
	} return memory;
}

