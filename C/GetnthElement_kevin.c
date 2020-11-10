/* Tuliskan header di sini berisi nama, dll */
/* Kevin Kencana 18219050*/
#include "diantarakita.h"
#include <stdio.h>

int GetnthElement(List L, int r)
{
	int X = 1;
	address P = First(L);
	while(X < r){
		P = Next(P);
		X++;
	}
	return Info(P);
}
