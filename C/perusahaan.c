#include <stdio.h>
#include "list.h"

int main(){
	IdxType N;
	IdxType i;
	ElType v;
	scanf("%d", &N);
	List T1;
	MakeEmpty(*T1);
	List T2;
	MakeEmpty(*T2);
	i = IdxMin+1;
	scanf("%d", &v);
	InsertFirst(*T1, v);
	while (i <= N){
		scanf("%d", &v);
		InsertAt(*T1,i,v);
		i = i + 1;
	}
	i = IdxMin+1;
	scanf("%d", &v);
	InsertFirst(*T2, v);
	while (i <= N){
		scanf("%d", &v);
		InsertAt(*T2,i,v);)
		i = i + 1;
	}
	i = IdxMin;
	while (i <= N){
		printf("%d ", i);
		printf("%d\n", (T1[i] + T2[i]));
		i = i + 1;
	}
	
	
}
