/* Kevin Kencana 18219050*/
#include "listdp.h"
#include <stdio.h>
#include "stdlib.h"

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
	return (First(L) == Nil && Last(L) == Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
	First(*L) = Nil;
	Last(*L) = Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
	address P;
	P = (address) malloc (sizeof(ElmtList));
	Info(P) = X;
	Next(P) = Nil;
	Prev(P) = Nil;
	if (Info(P) == X){
		return P;
	}
	else {
		return Nil;
	}
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */

void Dealokasi (address P){
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
	address P = First(L);
	boolean found = false;
	while (P != Last(L) && found == false){
		if (Info(P) == X){
			found = true;
		}
		else{
			P = Next(P);
		}
	}
	/* P ada di Last atau ada di address dengan Info X*/
	if (Info(P) == X){ /*ditemukan X dalam List*/
		return P;
	}
	else{
		return Nil;
	}
	
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
	address P = Alokasi(X);
	if (P != Nil){
		InsertFirst(L,P);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
	address P = Alokasi(X);
	if (P != Nil){
		InsertLast(L,P);
	}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
	address P;
	DelFirst(L,&P);
	/* P berisi address yang akan didealokasi*/
	*X = Info(P);
	Dealokasi(P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
	address P;
	DelLast(L,&P);
	*X = Info(P);
	Dealokasi(P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
	Next(P) = First(*L);
	if (!IsEmpty(*L)){ /* jika list tidak kosong, prev first akan nunjuk ke elemen P dari yang awalnya Nil*/
		Prev(First(*L)) = P;
	}
	else{
		Last(*L) = P; /* Jika P menjadi elemen satu-satunya list, First = Last = P*/
	}
	First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
	Prev(P) = Last(*L);
	if (!IsEmpty(*L)){ /* List tidak kosong*/
		Next(Last(*L)) = P; /*Last sblmnya akan menunjukkan ke P*/
	}
	else{ /*P menjadi elemen satu-satunya list*/
		First(*L) = P; /*First = Last = P*/
	}
	Last(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
	if (Next(Prec) != Nil){ /* Prec bukan last*/
		Prev(Next(Prec)) = P; /*prev elemen setelah prec akan nunjuk P*/
	}
	else{
		Last(*L) = P; /* Jika prec adalah last, maka P menjadi last yang baru*/
	}
	Next(P) = Next(Prec); 
	Prev(P) = Prec;
	Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ){
	if (Prev(Succ) != Nil){ /* Succ bukan elemen pertama list*/
		Next(Prev(Succ)) = P;
	}
	else{ /* Succ adalah elemen pertama*/
		First(*L) = P; /* P menjadi elemen pertama list*/
	}
	Prev(P) = Prev(Succ);
	Next(P) = Succ;
	Prev(Succ) = P;
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
	*P = First(*L); 
	if (First(*L) == Last(*L)){ /* List L hanya ada satu elemen*/
		Last(*L) = Nil; /* Last dan First L akan menjadi Nil*/
	}
	else{
		Prev(Next(First(*L))) = Nil; /* Prev dari elemen setelah first akan menjadi Nil*/
	}
	First(*L) = Next(First(*L));
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
	*P = Last(*L); 
	if (First(*L) == Last(*L)){ /* List L hanya memiliki 1 elemen*/
		First(*L) = Nil; /* First dan Last L akan menjadi Nil*/
	}
	else{
		Next(Prev(Last(*L))) = Nil; /*Next dari elemen sebelum last akan menjadi Nil*/
	}
	Last(*L) = Prev(Last(*L));
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotype X){
	address P = Search(*L,X);
	if (P != Nil){ /*X ada di List dengan address P*/
		if (First(*L) == Last(*L)){ /* P adalah satu-satunya elemen List*/
			First(*L) == Nil;
			Last(*L) == Nil;
		}
		else if (P == First(*L)){ /* P adalah first*/
			Prev(Next(P)) = Nil;
			First(*L) = Next(First(*L));
		}
		else if (P == Last(*L)){ /* P adalah last*/
			Next(Prev(P)) = Nil;
			Last(*L) = Prev(Last(*L));
		}
		else{ /* P ada di tengah-tengah list*/
			Next(Prev(P)) = Next(P);
			Prev(Next(P)) = Prev(P);
		}
		Dealokasi(P);
	}
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec){
	*Pdel = Next(Prec);
	if (Next(Next(Prec)) != Nil){ /* Pdel bukan last*/
		Prev(Next(*Pdel)) = Prec;
	}
	else{ /* Pdel adalah ;ast*/
		Last(*L) = Prec; /* Prec menjadi last*/
	}
	Next(Prec) = Next(Next(Prec));
	Next(*Pdel) = Nil;
	Prev(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ){
	*Pdel = Prev(Succ);
	if (Prev(Prev(Succ)) != Nil){ /*Pdel bukan first*/
		Next(Prev(*Pdel)) = Succ;
	}
	else{ /* Pdel adalah first*/
		First(*L) = Succ; /*Succ menjadi first*/
	}
	Prev(Succ) = Prev(Prev(Succ));
	Next(*Pdel) = Nil;
	Prev(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
	if (IsEmpty(L)){
		printf("[]");
	}
	else{
		printf("[");
		address P = First(L);
		while (P != Last(L)){
			printf("%d,", Info(P));
			P = Next(P);
		}
		printf("%d]", Info(P));
	}
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L){
	if (IsEmpty(L)){
		printf("[]");
	}
	else{
		printf("[");
		address P = Last(L);
		while (P != First(L)){
			printf("%d,", Info(P));
			P = Prev(P);
		}
		printf("%d]", Info(P));
	}
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

