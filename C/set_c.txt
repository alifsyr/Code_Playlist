#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S){
	(*S).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmpty(Set S){
	return S.Count == Nil;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

bool IsFull(Set S){
	return S.Count == MaxEl;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt){
	if (IsMember((*S),Elmt) == false){
		(*S).Elements[(*S).Count] = Elmt;
		(*S).Count++;
	}
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt){
	if (IsMember((*S),Elmt) == true){
		address i = 0;
		while (i < (*S).Count && (*S).Elements[i] != Elmt){
			i++;
		}
		(*S).Count--;
		while (i < (*S).Count){
			(*S).Elements[i] = (*S).Elements[i+1];
			i++;
		}
		
	}
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

bool IsMember(Set S, infotype Elmt){
	bool found = false;
	address i = 0;
	while (found == false && i < S.Count){
		if (S.Elements[i] == Elmt){
			found = true;
		}
		else{
			i++;
		}
	}
	return found;
}
/* Mengembalikan true jika Elmt adalah member dari S */
