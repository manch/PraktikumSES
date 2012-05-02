/*
 * CStaticAllocator.h
 *
 *  Created on: 23.04.2012
 *      Author: istchmanu
 */

#ifndef CSTATICALLOCATOR_H_
#define CSTATICALLOCATOR_H_

#include "IAllocator.h"
#include <cstdlib>
#include <iostream.h>
#include <stdlib.h>
#include <stdint.h>

#include "CDummy.h"

using namespace std;

class CStaticAllocator : public IAllocator {
public:
	static IAllocator * getAllocator();
	void *allocate(size_t memSize){
		return ::getStaticMemory(memSize);
	};
	void deallocate(void * memSize){};
	//CStaticAllocator();
	//CStaticAllocator *sAllocatorPtr;
	CStaticAllocator(){};
private:
	friend class CDummy;
	//static CStaticAllocator *sAllocatorPtr;
	static IAllocator * sAllocatorPtr;
	//CStaticAllocator(){};
	virtual ~CStaticAllocator(){};

};

#endif /* CSTATICALLOCATOR_H_ */
