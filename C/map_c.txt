#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M){
	(*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmpty(Map M){
	return M.Count == Nil;
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

bool IsFull(Map M){
	return M.Count == MaxEl;
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k){
	address i = 0;
	bool found = false;
	while (i < M.Count && found == false){
		if (M.Elements[i].Key == k){
			return M.Elements[i].Value;
			found = true;
		}
		else{
			i++;
		}
	}
}
/* Mengembalikan nilai value dengan key k dari M */


void Insert(Map *M, keytype k, valuetype v){
	if (IsMember((*M),k) == false){
		(*M).Elements[(*M).Count].Key = k;
		(*M).Elements[(*M).Count].Value = v;
		(*M).Count++;
	}
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, keytype k){
	if (IsMember((*M),k) == true){
		address i = 0;
		while (i < (*M).Count && (*M).Elements[i].Key != k){
			i++;
		}
		(*M).Count--;
		while (i < (*M).Count){
			(*M).Elements[i].Key = (*M).Elements[i+1].Key;
			(*M).Elements[i].Value = (*M).Elements[i+1].Value;
			i++;
		}
	}
}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

bool IsMember(Map M, keytype k){
	if (IsEmpty(M)){
		return false;
	}
	else{
		address i = 0;
		bool found = false;
		while (i < M.Count && found == false){
			if (M.Elements[i].Key == k){
				found = true;
			}
			i++;
		}
		return found;
	}
}
/* Mengembalikan true jika k adalah member dari M */
