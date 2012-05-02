#include "FWMemory.h"

char * getStaticMemory(size_t memSize)
{
  /*/sMutex.take();
  //ASSERTION(sCurrentPtr + memSize < sMemEndPtr)
  char *retPtr = sCurrentPtr;
  sCurrentPtr += MAKE_ALIGNMENT_SIZE(memSize);
  //sMutex.give();
  return retPtr;*/

	if(sCurrentPtr + memSize > endPtr)
	{
		return 0;
	}
	char * rtPtr = sCurrentPtr;
	sCurrentPtr += MAKE_ALIGMENT_SIZE(memSize);
	//cout << "Es wurden " << memSize << " Byte reserviert! " << endl;
	return rtPtr;
}
