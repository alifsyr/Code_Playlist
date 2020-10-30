#include "circular_queue.h"
#include <stdlib.h>

boolean IsEmpty (Queue Q){
	return (Q.HEAD == NIL && Q.TAIL == NIL);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q){
	return (Q.HEAD == 0 && Q.TAIL == (Q.MaxEl)-1);
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int Length (Queue Q){
	if (IsEmpty(Q)) {
		return 0;
	}
	else if (Q.TAIL >= Q.HEAD){
		return (Q.TAIL)-(Q.HEAD)+1;
	}
	else{ /* Ketika Tail berada di depan Head*/
		return (Q.MaxEl-Q.HEAD) + (Q.TAIL+1);
	}	
}
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
int MaxLength (Queue Q){
	return Q.MaxEl;
}
/* Mengirimkan kapasitas jumlah elemen Q */

/* *** Kreator *** */
Queue CreateQueue (int Max){
	Queue Q;
	Q.Tab = (ElType *) malloc (Max * sizeof(ElType));
	if (Q.Tab != NULL){
		Q.MaxEl = Max;
		Q.HEAD = NIL;
		Q.TAIL = NIL;
	}
	else {
		Q.MaxEl = 0;
	}
	return Q;
}
/* Proses : Melakukan alokasi memori, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/*   Jika alokasi berhasil, Tab dialokasi berukuran Max */
/*   Jika alokasi gagal, Q kosong dengan MaxEl=0 */

/* *** Destruktor *** */
void DeleteQueue (Queue * Q){
	(*Q).MaxEl = 0;
	free((*Q).Tab);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. membebaskan memori Tab, Q.MaxEl di-set 0 */

/* *** Primitif Add/Delete *** */
void Push (Queue * Q, ElType X){
	if ((*Q).HEAD == NIL && (*Q).TAIL == NIL){
		(*Q).HEAD = 0;
	}
	(*Q).TAIL = ((*Q).TAIL+1)%(*Q).MaxEl; 
	(*Q).Tab[(*Q).TAIL] = X;
	
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
ElType Pop (Queue * Q){
	ElType *X;
	*X = (*Q).Tab[(*Q).HEAD];
	if ((*Q).HEAD == (*Q).TAIL){
		(*Q).HEAD = NIL;
		(*Q).TAIL = NIL;
	}
	else{
	
		(*Q).HEAD = ((*Q).HEAD+1)%(*Q).MaxEl;
	}
	return *X;
}
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
ElType Front (Queue Q){
	return Q.Tab[Q.HEAD];
}
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */

/* *** Utilitas *** */
Queue CopyQueue (Queue Q){
	IdxType i;
	Queue *Qout;
	*Qout = CreateQueue(Q.MaxEl);
	i = Q.HEAD;
	while (i <= Q.TAIL){
		Push(Qout, Q.Tab[i]);
		i++;
	}
	return *Qout;
}
/* Proses: Mengembalikan Queue baru dengan isi antrean sama seperti Q */
/* I.S. Q pernah dialokasi */
/* F.S. Queue baru dengan nilai isi antrean sama seperti Q;
        HEAD pada Queue baru dimulai dari 0 */

