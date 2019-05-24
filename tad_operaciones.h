#ifndef TAD_OPERACIONES_H
#define TAD_OPERACIONES_H

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
void inserta_nodo_generico(ptrData *cab, ptrData x);
ptrSet generaTr();
ptrSet generaAhorasixd();
#endif
