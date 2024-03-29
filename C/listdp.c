#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

/*  
    NIM/Nama    : 18219036/Zachrandika Alif Syahreza
    Tanggal     : 12 November 2020
    Topik       : List Double Pointer
    Deskripsi   : Implementasi listdp.h
*/

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    return First(L) == Nil && Last(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    First(*L) = Nil;
    Last(*L) = Nil; 
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
    address P;
    P = (address) malloc (sizeof(address));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
    }
    return P;

}
void Dealokasi (address P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    address P;
    boolean found = false;
    P = First(L);
    while (P != Nil && !found){
        if (Info(P) == X){
        found = true;
        }
        else{
        P = Next(P);
        }
    }
    if (found){
        return P;
    } 
    else{
        return Nil;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P;
    P = Alokasi(X);
    if (P!= Nil){
        InsertFirst(L,P);
    }
}
void InsVLast (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P;
    P = Alokasi(X);
    if (P!=Nil){
        InsertLast(L,P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address P;
    DelFirst(L,&P);
    *X = Info(P);
    Dealokasi(P);
}
void DelVLast (List *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address P;
    DelLast(L,&P);
    *X = Info(P);
    Dealokasi(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    Next(P) = First(*L);
    if (IsEmpty(*L)){
        Last(*L) = P;
        Prev(P) = Nil;
    }
    else{
        Prev(First(*L)) = P;
    }
    First(*L) = P;
}
void InsertLast (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    Prev(P) = Last(*L);
    if (!IsEmpty(*L)){
        Next(Last(*L)) = P;
        Next(P) = Nil;
    }
    else{
        First(*L) = P;
        Next(P) = Nil;
    }
    Last(*L) = P;
}
void InsertAfter (List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    if (Next(Prec) == Nil){
        Last(*L) = P;
    }
    else{
        Prev(Next(Prec)) = P;
    }
    Next(P) = Next(Prec);
    Prev(P) = Prec;
    Next(Prec) = P;
}
void InsertBefore (List *L, address P, address Succ){
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
	if (Prev(Succ) != Nil){
		Next(Prev(Succ)) = P;
	}
	else{
		First(*L) = P;
	}
	Prev(P) = Prev(Succ);
	Next(P) = Succ;
	Prev(Succ) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
	*P = First(*L);
	First(*L) = Next(*P);
	if (First(*L) != Nil){
		Prev(First(*L)) = Nil;	
	}
    else{
		Last(*L) = Nil;
	}
	Next(*P) = Nil;
}

void DelLast (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
    *P = Last(*L);
    if (Last(*L) == First(*L)){
        First(*L) = Nil;
    }
    else{
        Next(Prev(Last(*L))) = Nil;
    }
    Last(*L) = Prev(*P);
    Next(*P) = Nil;
    Prev(*P) = Nil;
}
void DelP (List *L, infotype X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    address P,Prec;
    if (Search(*L,X) != Nil){
        if (X == Info(First(*L))){
        DelVFirst(L,&X);
        }
        else{
        Prec = First(*L);
        while (Info(Next(Prec)) != X){
            Prec = Next(Prec);
        }
        DelAfter(L,&P,Prec);
        Dealokasi(P);
        }
    }
    }
void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
	if (Last(*L) == Next(Prec)){
		DelLast(L,Pdel);
	} 
    else{
		*Pdel = Next(Prec);
		Next(Prec) = Next(*Pdel);
		Prev(Next(*Pdel)) = Prec;
		Prev(*Pdel) = Nil;
		Next(*Pdel) = Nil;
	}
}
void DelBefore (List *L, address *Pdel, address Succ){
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
	*Pdel = Prev(Succ);
	if (Prev(Prev(Succ)) != Nil){
		Next(Prev(*Pdel)) = Succ;
	}
	else{ 
		First(*L) = Succ; 
	}
	Prev(Succ) = Prev(Prev(Succ));
	Next(*Pdel) = Nil;
	Prev(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    address P;
    if (IsEmpty(L)){
        printf("[]");
    } 
    else{
        P = First(L);
        printf("[");
        while (P!=Nil){
        printf("%d",Info(P));
        if ( Next(P) == Nil){
            printf("]");
        } 
        else{
            printf(",");
        }
        P = Next(P);
        }
    }
}
void PrintBackward (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
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