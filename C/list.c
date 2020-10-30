#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List MakeList(){
	List list;
	list.A =  (ElType *) malloc (InitialSize*sizeof(ElType));
	list.Capacity = InitialSize;
	list.Neff = 0;
	return list;
}
void DeallocateList(List *list){
	free((*list).A);
	(*list).Neff = 0;
}
boolean IsEmpty(List list){
	return (list.Neff == 0); /* return true jika tidak ada elemen efektif/array kosong*/
}
int Length(List list){
	return list.Neff;
}
ElType Get(List list, IdxType i){
	return list.A[i];
}
int GetCapacity (List list){
	return list.Capacity;
}
void InsertAt(List *list, ElType el, IdxType i){
	IdxType len = ((*list).Neff) + 1;
	while (i < len){
		(*list).A[len] = (*list).A[len-1]; /* menggeser elemen > i ke kenan*/
		len = len - 1;
		}
		/* sekarang len = i dimana list.A[i] akan diisi*/
	(*list).A[i] = el;
	(*list).Neff += 1;
}
void InsertLast(List *list, ElType el){
	(*list).A[((*list).Neff)+1] = el;
	(*list).Neff += 1;
}
void InsertFirst(List *list, ElType el){
	IdxType i = (*list).Neff; 
	while (i > 0){
		(*list).A[i+1] = (*list).A[i]; /* menggeser semua elemen ke kanan*/
		i -= 1;
		}
	/* sekarang i = 0*/
	(*list).A[i] = el;
	(*list).Neff += 1;
}
	

	
	
	
	

