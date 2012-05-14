#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *last(void*){
  int a[50000];
  for ( int i = 0 ; i < 50000 ; i++) {
    a[i] = i;
  }
}


int main(int argc, char *agrv[]){
  pthread_t thread[50000];
  while(1){
    pthread_attr_t threadAttr;
    pthread_attr_init(&threadAttr);
    for ( int i = 0; i < 50000 ; i++){
      pthread_create(&thread[i],&threadAttr,last,NULL);
    }
  }
  return 0;
}
