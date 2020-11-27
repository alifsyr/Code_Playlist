/* Kevin Kencana 18219050 */
#include "ternary_search_tree.h"


/* *** Konstruktor *** */
TernaryTree Tree (infotype Akar){
	TernaryTree P;
	P = (TernaryTree) malloc (sizeof(Node));
	Info(P) = Akar;
	Left(P) = Nil;
	Right(P) = Nil;
	Middle(P) = Nil;
	if (Info(P) == Akar){ /* Alokasi berhasil*/
		return P;
	}
	else{ /* Alokasi gagal */
		return Nil;
	}
}
/* Menghasilkan sebuah pohon ternary dengan nilai info root = Akar */
/* left, middle, dan right bernilai Nil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */

/* Manajemen Memory */
addrNode AlokNode (infotype X){
	addrNode P;
	P = (addrNode) malloc (sizeof(Node));
	Info(P) = X;
	Left(P) = Nil;
	Right(P) = Nil;
	Middle(P) = Nil;
	if (Info(P) == X){ /* Alokasi berhasil*/
		return P;
	}
	else{ /* Alokasi gagal*/
		return Nil;
	}
}
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil, dan Middle(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokNode (addrNode P){
	free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (TernaryTree P){
	return (Info(P) == Nil && Left(P) == Nil && Right(P) == Nil && Middle(P) == Nil);
}
/* Mengirimkan true jika P adalah pohon ternary kosong */
boolean IsTreeOneElmt (TernaryTree P){
	return (Info(P) != Nil && Left(P) == Nil && Right(P) == Nil && Middle(P) == Nil);
}
/* Mengirimkan true jika P adalah pohon ternary tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft (TernaryTree P){
	if (IsTreeEmpty(P)){ /* Cek apakah P kosong*/
		return false;
	}
	else{
		if (Right(P) == Nil && Middle(P) == Nil && Left(P) != Nil){ /* Jika P ada subpohon bukan kiri*/
			return true;
		}
	}		
}
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerMiddle (TernaryTree P){
	if (IsTreeEmpty(P)){ /* Cek apakah P kosong*/
		return false;
	}
	else{
		if (Right(P) == Nil && Left(P) == Nil && Middle(P) != Nil){ /* Jika P ada subpohon bukan kiri*/
			return true;
		}
	}		
}

/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon unermiddle: hanya mempunyai subpohon tengah */
boolean IsUnerRight (TernaryTree P){
	if (IsTreeEmpty(P)){ /* Cek apakah P kosong*/
		return false;
	}
	else{
		if (Middle(P) == Nil && Left(P) == Nil && Right(P) != Nil){ /* Jika P ada subpohon bukan kiri*/
			return true;
		}
	}
}
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBinary (TernaryTree P){
	if (IsTreeEmpty(P)){ /* Cek apakah pohon kosong*/
		return false;
	}
	else{
		if (IsTreeOneElmt(P)){ /* basis*/
			return true;
		}
		else{ /* Rekurens*/
			/* ada 3 kemungkinan, 2 dari 3 subpohon yang dimiliki*/
			if (Left(P) != Nil && Right(P) != Nil && Middle(P) == Nil){
				return (IsBinary(Left(P)) && IsBinary(Right(P)));
			}
			else if (Middle(P) != Nil && Right(P) != Nil && Left(P) == Nil){
				return (IsBinary(Middle(P)) && IsBinary(Right(P)));
			}
			else if (Left(P) != Nil && Middle(P) != Nil && Right(P) == Nil){
				return (IsBinary(Left(P)) && IsBinary(Middle(P)));
			}
			else{ /* tidak memiliki 2 dari 3 subpohon*/
				return false;
			}
		}
	}
}
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon biner: mempunyai 2 dari 3 subpohon (kiri, tengah, kanan)*/
boolean IsTernary (TernaryTree P){
	if (IsTreeEmpty(P)){ /* Cek apakah pohon kosong*/
		return false;
	}
	else{
		if (IsTreeOneElmt(P)){ /* basis*/
			return true;
		}
		else{ /* rekurens*/
			if (Left(P) != Nil && Middle(P) != Nil && Right(P) != Nil){ /* memiliki semua subpohon*/
				return (IsTernary(Left(P)) && IsTernary(Middle(P)) && IsTernary(Right(P)));
			}
			else{ /* tidak memiliki semua sub pohon*/
				return false;
			}
		}
	}
}
/* Mengirimkan true jika pohon ternary tidak kosong P adalah pohon ternary lengkap: mempunyai seluruh subpohon kiri, tengah, kanan*/

/* *** Traversal *** */
void PrintTree (TernaryTree P){
	if (IsTreeEmpty(P)){ /* Basis*/
		printf(")");
	}
	else{ /* rekurens */
		printf("(");
		if (Info(P) != Nil){
			printf("%d", Info(P));
		}
		PrintTree(Left(P));
		PrintTree(Middle(P));
		PrintTree(Right(P));
		printf(")");
	}
}
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, pohon tengah, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   () adalah pohon kosong
   (A()()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()()())(C()()())(D()()())) adalah pohon dengan akar A dan subpohon kiri (B()()()) dan subpohon tengah (C()()()) dan subpohon kanan (D()()()) */

/* *** Searching *** */
int CountElmt (TernaryTree P, infotype X){
	if (IsTreeEmpty(P)){ /* Basis */
		return 0;
	}
	else{ /* rekurens*/
		if (Info(P) == X){ /* Jika Info(P) adalah X*/
			return 1 + CountElmt(Left(P),X) + CountElmt(Middle(P),X) + CountElmt(Right(P),X);
 		}
 		else{ /* Jika Info(P) bukan X*/
 			return 0 + CountElmt(Left(P),X) + CountElmt(Middle(P),X) + CountElmt(Right(P),X);
		 }
	}
}
/* Mengirimkan jumlah kemunculan nilai X pada node P (P bisa kosong) */
infotype GetSmallest (TernaryTree P){
	if (IsTreeOneElmt(P)){ /* basis*/
		return Info(P);
	}
	else{ /* rekurens, tergantung subpohon mana yang memiliki nilai node paling kecil*/ 
		if (GetSmallest(Left(P)) <= GetSmallest(Middle(P)) && GetSmallest(Left(P)) <= GetSmallest(Right(P))){
			return GetSmallest(Left(P));
		}
		else if (GetSmallest(Middle(P)) <= GetSmallest(Left(P)) && GetSmallest(Middle(P)) <= GetSmallest(Right(P))){
			return GetSmallest(Middle(P));
		}
		else if (GetSmallest(Right(P)) <= GetSmallest(Left(P)) && GetSmallest(Right(P)) <= GetSmallest(Middle(P))){
			return GetSmallest(Right(P));
		}
	}
}
/* Mengirimkan nilai node infotype (int) terkecil pada P (P tidak kosong) */
infotype GetLargest (TernaryTree P){
	if (IsTreeOneElmt(P)){ /* basis*/
		return Info(P);
	}
	else{ /* rekurens, tergantung subpohon mana yang memiliki nilai node paling besar*/ 
		if (GetLargest(Left(P)) >= GetLargest(Middle(P)) && GetLargest(Left(P)) >= GetLargest(Right(P))){
			return GetLargest(Left(P));
		}
		else if (GetLargest(Middle(P)) >= GetLargest(Left(P)) && GetLargest(Middle(P)) >= GetLargest(Right(P))){
			return GetLargest(Middle(P));
		}
		else if (GetLargest(Right(P)) >= GetLargest(Left(P)) && GetLargest(Right(P)) >= GetLargest(Middle(P))){
			return GetLargest(Right(P));
		}
	}
}
/* Mengirimkan nilai node infotype (int) terbesar pada P (P tidak kosong) */
infotype GetMode (TernaryTree P){
	if (IsTreeOneElmt(P)){
		return Info(P);
	}
} /* gak cukup waktunya :( */
/* Mengirimkan nilai node infotype (int) dengan kemunculan paling banyak (modus) pada P (P tidak kosong)*/

/* *** Fungsi-Fungsi Lain *** */
int NbElmt (TernaryTree P){
	if (IsTreeEmpty(P)){ /* Basis*/
		return 0;
	}
	else{ /* Rekurens*/
		return 1 + NbElmt(Left(P)) + NbElmt(Middle(P)) + NbElmt(Right(P));
	}
}
/* Mengirimkan banyaknya elemen (node) pohon ternary P */
int NbUniqueElmt (TernaryTree P){
	if (IsTreeEmpty(P)){ /* Basis */
		return 0;
	}
	else{ /* rekurens */
		if (CountElmt(P,Info(P)) > 1){ /* Jika elemen tidak unik, maka tidak dihitung */
			return 0 + NbUniqueElmt(Left(P)) + NbUniqueElmt(Middle(P)) + NbUniqueElmt(Right(P));
		}
		else{ /* Elemen unik*/
			return 1 + NbUniqueElmt(Left(P)) + NbUniqueElmt(Middle(P)) + NbUniqueElmt(Right(P));
		}
	}
}
/* Mengirimkan banyaknya elemen (node) dengan infotype unik pada pohon ternary P */
int NbDaun (TernaryTree P){
	if (IsTreeOneElmt(P)){ /* Basis */
		return 1;
	}
	else{ /* Rekurens*/
		if (IsTernary(P)){ /* P punya 3 subpohon*/
			return NbDaun(Left(P)) + NbDaun(Middle(P)) + NbDaun(Right(P));
		}
		else if (IsBinary(P)){ /* P punya 2 subpohon */
			if (Left(P) == Nil){
				return NbDaun(Middle(P)) + NbDaun(Right(P));
			}
			else if (Middle(P) == Nil){
				return NbDaun(Left(P)) + NbDaun(Right(P));
			}
			else{ /* Right(P) == Nil */
				return NbDaun(Left(P)) + NbDaun(Middle(P));
			}
		}
		/* P punya 1 sub pohon */
		else if (IsUnerLeft(P)){
			return NbDaun(Left(P));
		}
		else if (IsUnerMiddle(P)){
			return NbDaun(Middle(P));
		}
		else if (IsUnerRight(P)){
			return NbDaun(Right(P));
		}
	}
}
/* Mengirimkan banyaknya daun (node) pohon ternary P */
/* Prekondisi: P tidak kosong */
int Tinggi (TernaryTree P){
	if (IsTreeEmpty(P)){ /* Basis*/
		return 0;	
	}
	else{ /* rekurens, tergantung subpohon mana yang memiliki tinggi lebih besar*/
		if (Tinggi(Left(P)) >= Tinggi(Middle(P)) && Tinggi(Left(P)) >= Tinggi(Right(P))){
			return 1 + Tinggi(Left(P));
		}
		else if (Tinggi(Middle(P)) >= Tinggi(Right(P)) && Tinggi(Middle(P)) >= Tinggi(Left(P))){
			return 1 + Tinggi(Middle(P));
		}
		else if (Tinggi(Right(P)) >= Tinggi(Left(P)) && Tinggi(Right(P)) >= Tinggi(Middle(P))){
			return 1 + Tinggi(Middle(P));
		}
}
}
/* Pohon ternary mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim tinggi dari pohon, contoh:
   () --> 0
   (A()()()) --> 1
   (A(B()()())()()) --> 2 */

/* *** Operasi lain *** */
void AddElmt (TernaryTree *P, infotype X){
	addrNode PNode = AlokNode(X);
	if (IsTreeEmpty(*P)){
		*P = PNode; /* PNode jadi P baru */	
	}
	else{
		if (X < Info(*P)){
			if (Left(*P) == Nil){
				Left(*P) = PNode;
			}
			else{ /* Left P sudah teralokasi, maka PNode akan menjadi subphon untuk Left(P) */
				AddElmt(&Left(*P),X);
			}
		}
		else if (X == Info(*P)){
			if (Middle(*P) == Nil){
				Middle(*P) = PNode;
			}
			else{ /* Left P sudah teralokasi, maka PNode akan menjadi subphon untuk Middle(P) */
				AddElmt(&Middle(*P),X);
			}
 		}
 		else if (X > Info(*P)){
 			if (Right(*P) == Nil){
				Right(*P) = PNode;
			}
			else{ /* Left P sudah teralokasi, maka PNode akan menjadi subphon untuk Right(P) */
				AddElmt(&Right(*P),X);
			}
		 }
	}
}
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun sesuai definisi ternary search tree */
void DelDaun (TernaryTree *P, infotype X){
	if (IsTreeOneElmt(*P)){ /* Basis, elemen tersebut sudah pasti bernilai X*/
		DealokNode(*P);
	}
	else{ /* rekurens*/
		if (CountElmt(Left(*P),X) > 0){
			DelDaun(&Left(*P),X);
		}
		else if (CountElmt(Middle(*P),X) > 0){
			DelDaun(&Middle(*P),X);
		}
		else if (CountElmt(Right(*P),X) > 0){
			DelDaun(&Right(*P),X);
		}
	}
}
/* I.S. P tidak kosong, ada 1 daun bernilai X. */
/* F.S. Menghapus 1 daun bernilai X dari P. */

