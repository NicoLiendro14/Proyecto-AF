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
/*dataPtr add_nodo(charPtr letra){
dataPtr aux;
aux=(dataPtr)malloc(sizeof(dataPtr));
aux->dato=(dataPtr)letra;
aux->sig=NULL;
return aux;
}

dataPtr create_nodo(){
dataPtr aux=NULL;
return aux;
}

charPtr addSimb(char letra){
charPtr simb;
simb=(charPtr)malloc(sizeof(charPtr));
simb->valor=letra;
return simb;
}
charPtr getValor(dataPtr nodo){
charPtr c1;
c1=(charPtr)nodo->dato;
return c1;
}
void insertNodo(dataPtr *cab, dataPtr x){
dataPtr aux;
if(*cab==NULL)
*cab=x;
else{
aux=*cab;
while(aux->sig!=NULL)
aux=aux->sig;
aux->sig=x;
}
}
dataPtr cargarAlfabeto(){
int i,n;
charPtr simb;
dataPtr cab,aux;
cab=create_nodo();
aux=create_nodo();
printf("\n Cantidad de simbolos a cargar: ");
scanf("%d",&n);
if(n==0)
return cab;
else{
for(i=1;i<=n;i++){
printf("\n Ingrese simbolo n° %d: ",i);
fflush(stdin);
scanf("%c",&simb->valor);
aux=add_nodo(simb);
insertNodo(&cab,aux);
}
return cab;
}
}


void muestraNodos(dataPtr nodo){
charPtr aux;
if(nodo==NULL)
printf("\n No hay elementos.");
else{
while(nodo!=NULL){
aux=getValor(nodo);
printf("\n Simbolo: %c",aux->valor );
nodo=nodo->sig;
}
}
}

*/
