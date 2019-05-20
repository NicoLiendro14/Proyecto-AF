#ifndef TAD_TIPO_H
#define TAD_TIPO_H

#include "cadena.h"

//NODE TYPE
#define DATA 1
#define INT 2
#define SET 3
#define LIST 4
#define STR 5

//Estructura
typedef struct dataType{
	int nodeType;
	struct dataType *dato;
	struct dataType *sig;
}nodoData;
typedef nodoData *ptrData;
	

typedef struct intType{
	int nodeType;
	int dato;
}nodoInt;

typedef nodoInt *ptrInt;

typedef struct setType{
	int nodeType;
	struct setType *dato;
	struct setType *sig;
}nodoSet;
typedef nodoSet *ptrSet;

typedef struct listType{
	int nodeType;
	struct listType *dato;
	struct listType *sig;
}nodoList;
typedef nodoList *ptrList;

typedef struct strType{
	int nodeType;
	tcadena dato;
}nodoStr;
typedef nodoStr *ptrStr;


//Modulos
ptrData crea_data();
ptrInt crea_int(int);
ptrSet crea_set();
ptrList crea_list();
ptrStr crea_str(tcadena);
#endif
