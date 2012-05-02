#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <algorithm>
#include <vector>
#include "CStaticAllocator.h"
#include "CTemporaryHeapAllocator.h"
using namespace std;

struct susi {
	char bert;
	char kalr;
	char otto;
	char hansPeter;
	char melanie;
};


void* operator new(size_t Type_size){
	void * speicher = getStaticMemory(Type_size);
	//cout << "Habe " << Type_size << " Reserveiert." << endl;
	if(speicher == NULL)
	{
		exit(-1);
	}
	return speicher;
}

void operator delete(void * obj)
{
	cout << "OKAY " << endl;
}


void *browse1(void*){
	for (int i = 0; i < 50 ; i++){
		int * dyn = new int;
		*dyn = 0xFF;
		asm("nop");

	}
}

void *browse2(void*){
	for (int i = 0; i < 50 ; i++){
		new int();
	}

}

void *browse3(void*){
	for (int i = 0; i < 50 ; i++){
		new int();
	}

}



int main(int argc, char *argv[]) {
/*	pthread_t p1, p2, p3;
	pthread_attr_t at1, at2, at3;

	pthread_attr_init(&at1);
	pthread_attr_setschedpolicy(&at1, SCHED_RR);

	pthread_attr_init(&at2);
	pthread_attr_setschedpolicy(&at2, SCHED_RR);

	pthread_attr_init(&at3);
	pthread_attr_setschedpolicy(&at3,SCHED_RR);


	pthread_create(&p1,&at1,browse1, NULL);
	pthread_create(&p2,&at2,browse2, NULL);
	pthread_create(&p3,&at3,browse3, NULL);

	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	pthread_join(p3,NULL);

*/
	IAllocator * temp;
	IAllocator * pupsi;
	temp = CStaticAllocator::getAllocator();
	cout << "Zeiger: " << temp << "." << endl;
	pupsi = CStaticAllocator::getAllocator();
	cout << "Zeiger2: " << pupsi << "." << endl;

	IAllocator * blabla;
	blabla = new CTemporaryHeapAllocator(sizeof(int));
	cout << "Zeiger3: " << blabla << "." << endl;



	return EXIT_SUCCESS;
}
