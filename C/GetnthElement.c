/*
    NIM/Nama    : 18219036/Zachrandika Alif Syahreza
    Tanggal     : 5 November 2020
*/

#include "diantarakita.h"
int GetnthElement(List L, int r)

{
    int x = 1;
	address P = First(L);
	while(x < r){
		P = Next(P);
		x++;
	}
	return Info(P);
}