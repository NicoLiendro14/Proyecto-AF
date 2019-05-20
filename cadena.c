#include "cadena.h"
#include <string.h>
#include <stdio.h>


int leeCad(tcadena cad){
	int j=0,ret=0;
	char c;
	c=getchar();
	while(c!=EOF && c!='\n' && j<tam-1){
		cad[j] = c;
		c = getchar();
		j++;
		ret = 1;
	}
	cad[j] = '\0';
	while(c!=EOF && c!='\n')
		c=getchar();
	return ret;
}
