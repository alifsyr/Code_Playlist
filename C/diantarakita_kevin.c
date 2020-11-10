/* Kevin Kencana 18219050*/

#include "diantarakita.h"
#include "stdlib.h"
#include <stdio.h>

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
	return (First(L) == Nil);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
	First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
	address P;
	P = (address) malloc (sizeof(ElmtList));
	Info(P) = X;
	Next(P) = Nil;
	if (Info(P) == X){
		return P;
	}
	else {
		return Nil;
	}
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=P */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){
	free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean FSearch (List L, infotype X){
	address P;
	if (IsEmpty(L)){
		return false;
	}
	else{
		P = First(L);
		while (Next(P) != First(L) && Info(P) != X){
			P = Next(P);
		}
		return (Info(P) == X);
	}
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan true. */
/* Jika tidak ada, mengirimkan false */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst (List *L, infotype X){
	address P;
	address last;
	if (FSearch((*L),X)){
		DeleteElement(L,X);
		}
	P = Alokasi(X);
	if (P != Nil){
		/* di sini X sudah pasti tidak ada di list*/
		if (IsEmpty(*L)){
			Next(P) = P;
		}
		else{
			last = First(*L);
			while (Next(last) != First(*L)){
				last = Next(last);
			}
			Next(P) = First(*L);
			Next(last) = P;
		}
		First(*L) = P;
	}
}
/* I.S. L mungkin kosong */
/* F.S. Mengecek apakah X ada di List. */
/* Jika ada, hapus X dari list. */
/* Selanjutnya melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsertLast (List *L, infotype X){
	address P;
	address last;
	if (FSearch((*L),X)){
		DeleteElement(L,X);
		}
	if (IsEmpty(*L)){
		InsertFirst(L,X);
	}
	else{
		P = Alokasi(X);
		if (P != Nil){
			/* di sini X sudah pasti tidak ada di list*/
			}
			else {
				last = First(*L);
				while (Next(last) != First(*L)){
					last = Next(last);
				}
				Next(last) = P;
				Next(P) = First(*L);
			}
		}
	}
/* I.S. L mungkin kosong */
/* F.S. Mengecek apakah X ada di List. */
/* Jika ada, hapus X dari list. */
/* Selanjutnya melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void InsertAfter (List *L, infotype X, infotype Y){
	address Py;
	address Px;
	if (FSearch((*L),Y)){
		DeleteElement(L,Y);
		}
	Py = Alokasi(Y);
	if (Py != Nil){
		if (FSearch((*L),X)){
			/* Y sudah pasti tidak ada di List*/
			Px = First(*L);
			while (Info(Px) != X){
				Px = Next(Px);
			}
			/*Px berisi info X*/
			Next(Py) = Next(Px);
			Next(Px) = Py;
		}
	}
}
/* I.S. List L mungkin kosong, Y mungkin ada di list, */
/*      Mungkin elemen X tidak ada pada list  */
/* F.S. Mencari X dan Y pada list. Jika X tidak ada I.S.=F.S. */
/*      Jika Y ada pada list, hapus Y dari list */
/*      Selanjutnya alokasi Y dan masukkan di list setelah X. */
void InsertBefore (List *L, infotype X, infotype Y){
	address Py;
	address Px;
	address precPx;
	if (FSearch((*L),Y)){
		DeleteElement(L,Y);
		}
	Py = Alokasi(Y);
	if (Py != Nil){
		if (FSearch((*L),X)){
			if (Info(First(*L)) == X){ /* jika X adalah first*/
				InsertFirst(L,Y);
			}
			else{
				Px = First(*L);
				precPx = Nil;
				while (Info(Px) != X){
					precPx = Px;
					Px = Next(Px);
				}
				/* Px berisi info X dan precPx adalah elemen sebelumnya Px*/
				Next(precPx) = Py;
				Next(Py) = Px;
			}
			/* Y sudah pasti tidak ada di List*/
			
		}
	}
}
/* I.S. List L mungkin kosong, Y mungkin ada di list, */
/*      Mungkin elemen X tidak ada pada list  */
/* F.S. Mencari X dan Y pada list. Jika X tidak ada I.S.=F.S. */
/*      Jika Y ada pada list, hapus Y dari list */
/*      Selanjutnya alokasi Y dan masukkan di list sebelum X. */
/*      Jika X pada I.S. adalah First, maka Y menjadi First pada F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst (List *L, infotype *X){
	address P;
	address last;
	P = First(*L);
	*X = Info(P);
	if (Next(First(*L)) == First(*L)) { /* Kasus satu elemen*/
		First(*L) = Nil;
	}
	else{
		last = First(*L);
		while (Next(last) != First(*L)){
			last = Next(last);
		}
		First(*L) = Next(First(*L));
		Next(last) = First(*L);
	}
	Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DeleteLast (List *L, infotype *X){
	address last;
	address preclast;
	last = First(*L);
	preclast = Nil;
	while (Next(last) != First(*L)){
		preclast = last;
		last = Next(last);
	}
	if (preclast == Nil){ /* kasus satu elemen*/
		First(*L) = Nil;
	}
	else{
		Next(preclast) = First(*L);
	}
	*X = Info(last);
	Dealokasi(&last);
	
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
void DeleteElement (List *L, infotype X){
	if (FSearch((*L),X)) {
		address P = First(*L);
		if (Info(First(*L)) == X){ /* cek apakah X adalah first*/
			if (Next(First(*L)) == First(*L)){ /* satu elemen saka*/
				First(*L) = Nil;
			}
			else{
				First(*L) = Next(First(*L));
			}
		}
		else{ /*X ada di list tapi bukan elemen pertama*/
			address Prec = Nil;
			while (Info(P) != X){
				Prec = P;
				P = Next(P);
			}
			Next(Prec) = Next(P);
		}
		Dealokasi(&P);
	}
}
/* I.S. list mungkin kosong */
/* F.S. Mencari X. Jika ada, hapus X */
/*      Jika pada I.S., X adalah First, maka elemen setelah X menjadi First, */
/*      KECUALI X adalah satu-satunya elemen */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
	if (IsEmpty(L)){
		printf("[]");
	}
	else{
		printf("[");
		address P = First(L);
		while (Next(P) != First(L)){
			printf("%d,", Info(P));
			P = Next(P);
		}
		printf("%d]", Info(P));
	}
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int CountElement (List L){
	int count = 0;
	if (IsEmpty(L)){
		return count;
	}
	else{ /* list tidak kosong*/
		address P = First(L);
		count++;
		while (Next(P) != First(L)){
			P = Next(P);
			count++;
		}
		return count;
	}
}
/* List L mungkin kosong */
/* Output banyaknya jumlah elemen pada list L */

/****************** PROSES TERHADAP LIST ******************/
void MoveLastToFirst(List *L){
	infotype X;
	if (Next(First(*L)) != First(*L)){ /* list lebih dari 1 elemen*/
		DeleteLast(L,&X);
		InsertFirst(L,X);
	}	
}

/* I.S. List mungkin kosong */
/* F.S. Jika list memiliki lebih dari 1 elemen, pindahkan elemen terakhir menjadi elemen pertama */
/* Tips: Perkara mudah jangan dibuat sulit */
