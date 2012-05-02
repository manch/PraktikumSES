/*
 * CSharedMemoryAllocator.cpp
 *
 *  Created on: 25.04.2012
 *      Author: istchmanu
 */

#include "CSharedMemoryAllocator.h"

extern int errno;

IAllocator * CSharedMemoryAllocator::sAllocatorPtr = 0;
CSharedMemoryAllocator::CSharedMemoryAllocator() {
	// TODO Auto-generated constructor stub
	int fd = shm_open("SharedMem",O_RDWR | O_CREAT | O_EXCL, FILE_MODE);
	bool success = true;
	if (fd == -1){
		cout << "Error on opening" << endl;
		fd = shm_open("SharedMem", O_RDWR, FILE_MODE);
		if( fd == -1){
			success = false;
			cout << "Check permission" << endl;
		}
		else{
			cout << "open an existing Memory" << endl;
		}
	}else{
		cout << "create new shared memory." << endl;
	}
	if (true == success){
		ftruncate(fd, 1000);
	}
	memPtr = (char *) mmap(NULL, 1000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
}

CSharedMemoryAllocator::~CSharedMemoryAllocator() {
	// TODO Auto-generated destructor stub
}
IAllocator * CSharedMemoryAllocator::getAllocator(){
	if (0 == sAllocatorPtr){
//		pthread_mutex_lock(&mutex);
		if ( 0 == sAllocatorPtr){
			//sAllocatorPtr = NEW_STATIC_DEFAULT(CStaticAllocator);
			sAllocatorPtr = new(getStaticMemory(sizeof(CSharedMemoryAllocator))) CSharedMemoryAllocator();
		}
	//	pthread_mutex_unlock(&mutex);
	}
	return sAllocatorPtr;
}

void * CSharedMemoryAllocator::allocate(size_t memSize){
	void * retPtr= memPtr;
	memPtr += memSize;
	//memPtr = MAKE_ALIGMENT_SIZE(memPtr);
	return retPtr;



}
