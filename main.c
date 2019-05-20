#include "tad_tipo.h"
#include "cadena.h"
#include <stdlib.h>
#include <stdio.h>
void inserta_nodo(ptrSet *cab, ptrSet x);
ptrStr getValor(ptrSet x);
void muestra(ptrSet lista);
ptrSet genera_conjunto(int);
ptrList crea_upla();
void muestraCompleto(ptrList);
void muestraFinal(ptrData g1);
int main(){
	//Creamos la 5upla
	//Como es una lista ordenada, el primero es un nodo list
	//ptrList lista=NULL;
	
	//lista=crea_list();
	
	/*ptrSet estados = NULL;
	
	estados=genera_conjunto(2);
	muestra(estados);*/
	ptrList lista=NULL;
	lista=crea_upla();
	//muestraCompleto(lista);
	
	return 0;
}

ptrList crea_upla(){
	int cant;
	ptrData g1=NULL,g2=NULL,g3=NULL;
	ptrList lista=NULL;
	ptrSet qo=NULL,sigma=NULL,estados=NULL,estFinal=NULL;
	ptrSet qo2=NULL,sigma2=NULL,estFinal2=NULL;
	//trans2=NULL trans=NULL,
	printf("\n \n \n \t CARGA DE AUTOMATA FINITO \n \n \n");
	printf("\n Cantidad de estados: ");
	scanf("%d",&cant);
	estados=genera_conjunto(cant);
	printf("\n \t ***ESTADOS*** \n");
	muestra(estados);
	printf("\n Cantidad de caracteres del alfabeto: ");
	scanf("%d",&cant);
	sigma=genera_conjunto(cant);
	printf("\n \t ***ALFABETO*** \n");
	muestra(sigma);
	/*printf("\n Transiciones: ");
	//trans=crea_set();
	printf("\n \t ***TRANSICIONES*** \n");*/
	printf("\n Estado inicial: ");
	qo=genera_conjunto(1);
	printf("\n \t ***ESTADO INICIAL*** \n");
	muestra(qo);
	printf("\n Cantidad de estados finales: ");
	scanf("%d",&cant);
	estFinal=genera_conjunto(cant);
	printf("\n \t ***ESTADO FINAL*** \n");
	muestra(estFinal);
	printf("\n \n \n \t ¡¡¡CARGA EXITOSA DEL AUTOMATA!!! \n \n \n");
	
	g1=crea_data();
	g2=crea_data();
	g3=crea_data();
	
	
	
	
	g1->dato=(ptrData)estados;
	g1->sig=g2;
	g2->dato=(ptrData)sigma;
	g2->sig=g3;
	g3->dato=(ptrData)qo;
	g3->sig=NULL;
	
	muestraFinal(g1);
	
	/*lista->dato=(ptrList)estados;
	lista->sig=(ptrList)sigma2;
	sigma2->dato=sigma;
	sigma2->sig=qo2;
	qo2->dato=qo;
	qo2->sig=estFinal2;
	estFinal2->dato=estFinal;
	estFinal2->sig=NULL;*/
	
	return lista;
	
	/*lista->dato=estados;
	lista->sig=sigma;*/
	
}
void muestraFinal(ptrData g1){
	printf("\n \n \t SUPONGO QUE ESTE ES EL MUESTRA FINAL XD \n \n");
	ptrSet aux1=NULL;
	if(g1==NULL){
		printf("\n SOS ALTO GIL TE SALIO MAL XD \n");
	}
	else{
		while(g1!=NULL){
			aux1=(ptrSet)g1->dato;
			muestra(aux1);
			g1=g1->sig;
		}
	}
}
ptrSet genera_conjunto(int n){
	int i;

	ptrStr str1=NULL;
	ptrSet estados=NULL,aux=NULL;
	tcadena cad1;
	
	
	for(i=1;i<=n;i++){
		printf("\n Caracter o cadena %d: ",i);
		fflush(stdin);
		leeCad(cad1);
		str1=crea_str(cad1);
		//printf("Valor: %s",str1->dato);
		aux=crea_set(str1);
		//aux->sig=NULL;
		//estados->sig=NULL;
		//printf(
		inserta_nodo(&estados,aux);
		
	}
	return estados;
}
void inserta_nodo(ptrSet *cab, ptrSet x){
	ptrSet aux=NULL;
	if(*cab!=NULL){
		aux=*cab;
		while(aux->sig!=NULL)
			aux=aux->sig;
		aux->sig=x;
	}
	else{
		*cab=x;
	}
}
void muestra(ptrSet lista){
	ptrStr aux=NULL;
	if(lista==NULL){
		printf("\n *** LISTA VACIA TONTO!!!");
	}
	else{
		while(lista!=NULL){
			aux=getValor(lista);
			printf("\n %s \n",aux->dato);
			lista=lista->sig;
		}
	}
}
void muestraCompleto(ptrList lista){
	printf("\n \t \t ***MUESTRA COMPLETO*** \n \n");
	ptrSet aux=NULL;
	ptrList aux2=NULL;
	aux=(ptrSet)lista->dato;
	printf("\n \t \t ***ESTADOS*** \n \n");
	muestra(aux);
	aux=(ptrSet)lista->sig;
	muestra(aux->dato);
}
ptrStr getValor(ptrSet x){
	ptrStr aux;
	aux=(ptrStr)x->dato;
	return aux;
}












