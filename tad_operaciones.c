#include "tad_tipo.h"
#include "cadena.h"
#include <stdlib.h>
#include <stdio.h>
#include "tad_operaciones.h"


ptrList crea_upla(){
	//Inicializo las variables
	int cant;
	ptrData g1=NULL,g2=NULL,g3=NULL,g4=NULL,g5=NULL;
	ptrList lista=NULL;
	ptrSet qo=NULL,sigma=NULL,delta=NULL,estados=NULL,estFinal=NULL;
	//Cargamos el AF
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
	
	//ACA VA EL CODIGO DE LA TRANSICION
	
	printf("\n Transiciones: ");
	delta=generaAhorasixd();
	printf("\n \t ***TRANSICIONES*** \n");
	muestra(delta);
	
	
	printf("\n Estado inicial: \n");
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
	g4=crea_data();
	g5=crea_data();
	
	g1->dato=(ptrData)estados;
	g1->sig=g2;
	g2->dato=(ptrData)sigma;
	g2->sig=g3;
	g3->dato=(ptrData)delta;
	g3->sig=g4;
	g4->dato=(ptrData)qo;
	g4->sig=g5;
	g5->dato=(ptrData)estFinal;
	g5->sig=NULL;
	
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



/*ptrData unionConjunto(){

}*/



void muestraFinal(ptrData g1){
	printf("\n \n \t ***AUTOMATA CARGADO*** \n \n");
	ptrSet aux1=NULL;
	if(g1==NULL){
		printf("\n ERROR EN LA MUESTRA! \n");
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
	//ptrData auxGen=NULL,cabGen=NULLL; auxGen=crea_data(); cabGen=crea_data();
	ptrStr str1=NULL;
	ptrSet estados=NULL,aux=NULL;
	tcadena cad1;
	for(i=1;i<=n;i++){
		printf("\n Caracter o cadena %d: ",i);
		fflush(stdin);
		leeCad(cad1);
		str1=crea_str(cad1);
		aux=crea_set(str1);
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
void inserta_nodo_generico(ptrData *cab, ptrData x){
	ptrData aux=NULL;
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
ptrSet generaTr(){
	
	ptrSet transi=NULL;
	printf("\n \n \t ***TRANSICIONES*** \n \n");
	printf("\n Ingrese en el siguiente orden: ");
	printf("\n 1-Estado \n2-Simbolo \n3-Estado de llegada: ");
	transi=genera_conjunto(3);
	return transi;
	
}

ptrSet generaAhorasixd(){
	ptrSet delta=NULL,aux=NULL;
	char op;
	
	do{
		
		aux=generaTr();
		inserta_nodo(&delta,aux);
		
		printf("\n Desea seguir ingresando transiciones? S/N");
		scanf("%c",&op);
		
		
	}while(op!='N'&&op!='n');
	
	return delta;
}

void muestra(ptrSet lista){
	ptrStr aux=NULL;
	if(lista==NULL){
		printf("\n ERROR! EL CONJUNTO ESTA VACIO");
	}
	else{
		printf("\n \n \t{");
		while(lista!=NULL){
			aux=getValor(lista);
			printf("%s",aux->dato);
			if(lista->sig!=NULL)
				printf(",");
			lista=lista->sig;
		}
		printf("}");
	}
}


ptrStr getValor(ptrSet x){ //Obtiene el STRING que tiene SET
	ptrStr aux;
	aux=(ptrStr)x->dato;
	return aux;
}

