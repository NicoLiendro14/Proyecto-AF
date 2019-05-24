#include "tad_tipo.h"
#include "cadena.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ptrData crea_data(){
	ptrData aux;
	aux=(ptrData)malloc(sizeof(struct dataType));
	aux->dato=NULL;
	aux->nodeType=1;
	aux->sig=NULL;
	return aux;
}
ptrInt crea_int(int num){
	ptrInt aux;
	aux=(ptrInt)malloc(sizeof(struct intType));
	aux->nodeType=2;
	aux->dato=num;
	return aux;
}
ptrSet crea_set(ptrStr cad){
	ptrSet aux;
	aux=(ptrSet)malloc(sizeof(struct setType));
	aux->dato=(ptrSet)cad;
	aux->nodeType=3;
	aux->sig=NULL;
	return aux;
}

ptrList crea_list(ptrData gen1){
	ptrList aux;
	aux=(ptrList)malloc(sizeof(struct listType));
	aux->dato=(ptrList)gen1;
	aux->nodeType=4;
	aux->sig=NULL;
	return aux;
}

ptrStr crea_str(tcadena cad1){
	ptrStr aux;
	aux=(ptrStr)malloc(sizeof(struct strType));
	aux->nodeType=5;
	//aux->dato=cad1;
	strcpy(aux->dato,cad1);
	return aux;
}

