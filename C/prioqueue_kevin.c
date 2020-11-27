/* Kevin Kencana 18219050 */
#include "prioqueue.h"

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X, int prio){
	*P = (address) malloc (sizeof(ElmtQueue));
	Prio(*P) = prio;
	Info(*P) = X;
	Next(*P) = Nil;
	if (Info(*P) != X){ /* Jika alokasi gagal*/
		*P = Nil;
	}
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X,
        Next(P)=Nil, dan Prio(P)=prio */
/*      P=Nil jika alokasi gagal */
void Dealokasi (address  P){
	free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmpty (Queue Q){
	return (Head(Q) == Nil && Tail(Q) == Nil);
}
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmt(Queue Q){
	if (IsEmpty(Q)){
		return 0;
	}
	else{
		int count = 0;
		address P = Head(Q);
		while (P != Tail(Q)){
			P = Next(P);
			count++;
		}
		/* P sekarang berada di Tail*/
		count++; /* increment terakhir untuk tail*/
		return count;
	}
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmpty(Queue * Q){
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk (i.e. Head(Q) = Nil dan Tail(Q) = Nil) */
/*** Primitif Add/Delete ***/
void Enqueue (Queue * Q, infotype X, int prio){
	/* Seperti insert after pada list linier*/
	address P;
	Alokasi(&P,X,prio);
	if (P != Nil){
		if (IsEmpty(*Q)){
			Head(*Q) = P;
			Tail(*Q) = P;
		}
		else{
			address Succ = Head(*Q); /* Succ adalah elemen dengan prioritas yang lebih rendah dari P*/
			address Prec = Nil; /* Prec adalah elemen suksesor sebelum Succ dengan prioritas yang lebih tinggi daripada Succ dan P*/
			while (Prio(Succ) >= Prio(P) && Succ != Tail(*Q)){
				Prec = Succ;
				Succ = Next(Succ);
			}
			/* Di sini Prec adalah suatu elemen dengan prioritas lebih tinggi/sama dari P dan Succ adalah elemen dengan prioritas lebih rendah dari P atau Tail dari Q*/
			if (Prec == Nil && Prio(Succ) < Prio(P)){ /* Jika P memiliki prioritas paling tinggi dan hanya satu elemen queue*/
				/* Seperti insert first*/
				Next(P) = Head(*Q);
				Head(*Q) = P;
			}
			else if (Prio(Succ) >= Prio(P)){ /* Jika P memiliki prioritas paling rendah*/
				/* seperti insert last*/
				Next(Succ) = P;
				Tail(*Q) = P;
			}
			else{ 
				/* Insert After Prec dan Insert Before Succ*/
				Next(P) = Succ;
				Next(Prec) = P;
			}	
		}
	}
}
/* Proses: Mengalokasi X dan menambahkan X pada posisi setelah element dengan 
   prioritas yang lebih tinggi/sama, dan sebelum element dengan prioritas yang 
   lebih rendah jika alokasi berhasil; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong */
/* F.S. X diletakkan setelah setelah element dengan prioritas yang lebih 
   tinggi/sama, dan sebelum element dengan prioritas yang lebih rendah.
   Apabila X diletakkan di posisi terakhir, maka TAIL = element X. */
void Dequeue (Queue * Q, infotype * X){
	*X = InfoHead(*Q);
	if (NbElmt(*Q) == 1){ /* jika hanya satu elemen, maka queue menjadi kosong*/
		Tail(*Q) = Nil;
	}
	address P = Head(*Q);
	Head(*Q) = Next(Head(*Q)); /* jika satu elemen, head akan menjadi nil*/
	Next(P) = Nil;
	Dealokasi(P);
}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
