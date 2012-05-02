/*
 * StaticMem.cpp
 *
 *  Created on: 16.04.2012
 *      Author: istchmanu
 */

#include "StaticMem.h"

char StaticMem::mem[MemSize];
char* StaticMem::sCurrentPtr;// = mem;
char* StaticMem::endPtr;// = mem + MemSize;


StaticMem::StaticMem() {
	// TODO Auto-generated constructor stub
	this->sCurrentPtr = this->mem;
	this->endPtr = this->mem + MemSize;
}


char * StaticMem::getStaticMem(size_t size) {
	if(this->sCurrentPtr + size > this->endPtr)
	{
		return 0;
	}
	char * rtPtr = this->sCurrentPtr;
	this->sCurrentPtr += MAKE_ALIGMENT_SIZE(size);
	cout << "Es wurden " << size << " Byte reserviert! " << endl;
	return rtPtr;
}
