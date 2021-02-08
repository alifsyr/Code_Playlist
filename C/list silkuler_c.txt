#include <stdio.h>
#include <stdlib.h>
#include "diantarakita.h"

/*  
    NIM/Nama    : 18219036/Zachrandika Alif Syahreza
    Tanggal     : 5 November 2020
    Topik       : List Sirkuler
    Deskripsi   : Implementasi diantarakita.h
*/

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
/* Mengirim true jika list kosong */
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=P */
/* Jika alokasi gagal, mengirimkan Nil */
    address P;
    P = (address) malloc(sizeof(ElmtList));
    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}
void Dealokasi (address *P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean FSearch (List L, infotype X){
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan true. */
/* Jika tidak ada, mengirimkan false */
    address P;
	if (IsEmpty(L)){
		return false;
	}    
    else{
        P = First(L);
        while (Info(P) != X && Next(P) != First(L)){
            P = Next(P);
        }
        return (Info(P) == X);
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Mengecek apakah X ada di List. */
/* Jika ada, hapus X dari list. */
/* Selanjutnya melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P;
    P = Alokasi(X);
    if( P != Nil){
        if( IsEmpty(*L) ){
            First(*L) = P;
            Next(P) = P;
        }
        else{
            if(FSearch(*L, X)){
                Dealokasi(&P);
            }
            Next(P) = First(*L);
            First(*L) = P;
        }
    }
}
void InsertLast (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Mengecek apakah X ada di List. */
/* Jika ada, hapus X dari list. */
/* Selanjutnya melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if(FSearch(*L,X)){
        if(IsEmpty(*L)){
            InsertFirst(L,X);
        }
        else{
            address P = Alokasi(X);
            address last = First(*L);
            while (Next(last) != First(*L)){
                last = Next(last);
            }
            Next(last) = P;
            Next(P) = First(*L);
        }
    }
}

void InsertAfter (List *L, infotype X, infotype Y){}
/* I.S. List L mungkin kosong, Y mungkin ada di list, */
/*      Mungkin elemen X tidak ada pada list  */
/* F.S. Mencari X dan Y pada list. Jika X tidak ada I.S.=F.S. */
/*      Jika Y ada pada list, hapus Y dari list */
/*      Selanjutnya alokasi Y dan masukkan di list setelah X. */
void InsertBefore (List *L, infotype X, infotype Y){}
/* I.S. List L mungkin kosong, Y mungkin ada di list, */
/*      Mungkin elemen X tidak ada pada list  */
/* F.S. Mencari X dan Y pada list. Jika X tidak ada I.S.=F.S. */
/*      Jika Y ada pada list, hapus Y dari list */
/*      Selanjutnya alokasi Y dan masukkan di list sebelum X. */
/*      Jika X pada I.S. adalah First, maka Y menjadi First pada F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst (List *L, infotype *X){}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DeleteLast (List *L, infotype *X){}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
void DeleteElement (List *L, infotype X){}
/* I.S. list mungkin kosong */
/* F.S. Mencari X. Jika ada, hapus X */
/*      Jika pada I.S., X adalah First, maka elemen setelah X menjadi First, */
/*      KECUALI X adalah satu-satunya elemen. Jika X adalah elemen satu-satunya, F.S. List kosong. */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int CountElement (List L){
/* List L mungkin kosong */
/* Output banyaknya jumlah elemen pada list L. Return 0 jika kosong. */
    int count = 0;
    address P = First(L);
    if (IsEmpty(L)){
        return count;
    }
    else{
        count++;  
        while (P != First(L)){
            count++;
            P = Next(P);
        }
    }
    return count;
}

/****************** PROSES TERHADAP LIST ******************/
void MoveLastToFirst(List *L){}
/* I.S. List mungkin kosong */
/* F.S. Jika list memiliki lebih dari 1 elemen, pindahkan elemen terakhir menjadi elemen pertama */
/* Tips: Perkara mudah jangan dibuat sulit */