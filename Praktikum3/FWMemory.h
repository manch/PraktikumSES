#include <stddef.h>
#include <new.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdint.h>
using namespace std;

extern char * getStaticMemory(size_t memSize);

#define MemSize 10000

static char mem[MemSize];
static char * sCurrentPtr = mem;
static char * endPtr = mem + MemSize;

//dynamische Speicherallokierung
#define NEW_DYNAMIC_DEFAULT(Typ) (new Typ())
#define NEW_DYNAMIC(Typ,ARGS) (new Typ ARGS)
#define NEW_DYNAMIC_ARRAY(Typ,size) (new Typ[size])
#define DELETE_DYNAMIC(var)(delete var)
#define DELETE_DYNAMIC_ARRAY(array) (delete[] array)

//statische Speicherallokierung
#define NEW_STATIC_DEFAULT(Typ)(new(getStaticMemory(sizeof(Typ)))Typ())
#define NEW_STATIC(Typ,ARGS)(new(getStaticMemory(sizeof(Typ)))Typ ARGS)
#define NEW_STATIC_ARRAY(Typ,size)(new(getStaticMemory(sizeof(Typ)*size))Typ[size])
#define DELETE_STATIC(var)
#define DELETE_STATIC_ARRAY(array)

#define MAKE_ALIGMENT_SIZE(size) ((((size)+(sizeof(INT32_MAX)-1))/sizeof(INT32_MAX))*sizeof(INT32_MAX))


