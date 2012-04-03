#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *browse1(void*){
	for(int i=0; i < 1000 ; i++){
		std::cout << "ich bin thread 1" << std::endl;
		//printf("Ich bin Nummer 1\n");
	}
}
void *browse2(void*){
	for(int i=0; i < 1000; i++){
		std::cout << "ich bin thread 2" << std::endl;
		//printf("Ich bin Nummer 2\n");
	}
	//printf ("ich bin der thread printf\n");
}

int main(int argc, char *argv[]) {


	/*pid_t kindpid = fork();
	for(int i = 0; i<100; i++)
	{
	switch(kindpid)
	{
		case -1:
			//fehler
			break;
		case 0:
			//Ich bin das Kind

			//std::cout << "Alle Kinder lieben SuessesSuessesSuessesSuessesSuessesSuessesSuessesSuessesSuesses" <<std::endl;
			printf("Alle Kinder lieben SuessesSuessesSuessesSuessesSuessesSuessesSuessesSuessesSuesses\n");

			break;
		default:
			//ICH BIN DEIN VATER
			//std::cout << "L!"<<std::endl;
			printf("L!\n");
			break;
		}
	}*/
	pthread_t p1, p2;
	pthread_attr_t at1,at2;

	pthread_attr_init(&at1);
	pthread_attr_setschedpolicy(&at1, SCHED_RR);
	//pthread_attr_
	pthread_attr_init(&at2);
	pthread_attr_setschedpolicy(&at2, SCHED_RR);


	pthread_create(&p1,&at1,browse1, NULL);
	pthread_create(&p2,&at2,browse2, NULL);

	pthread_join(p1,NULL);
	pthread_join(p2,NULL);

	return EXIT_SUCCESS;
}
