/*
 * CStaticAllocator.cpp
 *
 *  Created on: 23.04.2012
 *      Author: istchmanu
 */

#include "CStaticAllocator.h"
#include <pthread.h>

IAllocator * CStaticAllocator::sAllocatorPtr = 0;
//pthread_mutex_t mutex;
//pthread_mutex_init(&mutex, NULL);


IAllocator * CStaticAllocator::getAllocator(){
	if (0 == sAllocatorPtr){
//		pthread_mutex_lock(&mutex);
		if ( 0 == sAllocatorPtr){
			//sAllocatorPtr = NEW_STATIC_DEFAULT(CStaticAllocator);
			sAllocatorPtr = new(getStaticMemory(sizeof(CStaticAllocator))) CStaticAllocator();
		}
	//	pthread_mutex_unlock(&mutex);
	}
	return sAllocatorPtr;
}
