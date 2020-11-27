#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"

/*  
    NIM/Nama    : 18219036/Zachrandika Alif Syahreza
    Tanggal     : 19 November 2020
    Topik       : Priority Queue
    Deskripsi   : Implementasi prioqueue.h
*/
/* Prototype manajemen memori */
void Alokasi (address *P, infotype X, int prio){
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X,
        Next(P)=Nil, dan Prio(P)=prio */
/*      P=Nil jika alokasi gagal */
    *P = (address) malloc (sizeof(ElmtQueue));
    Info(*P) = X;
    Next(*P) = Nil;
    Prio(*P) = prio;
    if(Info(*P) != X){
        *P = Nil;
    }
}
void Dealokasi (address  P){
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
    free(P);
}
boolean IsEmpty (Queue Q){
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
    return Head(Q) == Nil && Tail(Q) == Nil;
}
int NbElmt(Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
    if (IsEmpty(Q)){
        return 0;
    }
    else{
        address P = Head(Q);
        int count = 0;
        while (P != Tail(Q)){
            P = Next(P);
            count ++;
        }
        count ++;
        return count;
    }
}
/*** Kreator ***/
void CreateEmpty(Queue * Q){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk (i.e. Head(Q) = Nil dan Tail(Q) = Nil) */
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}
/*** Primitif Add/Delete ***/
void Enqueue (Queue * Q, infotype X, int prio){}
/* Proses: Mengalokasi X dan menambahkan X pada posisi setelah element dengan  */
/* prioritas yang lebih tinggi/sama, dan sebelum element dengan prioritas yang */
/* lebih rendah jika alokasi berhasil; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong */
/* F.S. X diletakkan setelah setelah element dengan prioritas yang lebih */
/* tinggi/sama, dan sebelum element dengan prioritas yang lebih rendah.*/
/* Apabila X diletakkan di posisi terakhir, maka TAIL = element X. */
void Dequeue (Queue * Q, infotype * X){}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
/* elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
