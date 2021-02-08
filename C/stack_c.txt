#include "stack.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S){
	(*S).TOP = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsEmpty(Stack S){
	return (S.TOP == Nil);
}
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
bool IsFull(Stack S){
	return (S.TOP == MaxEl);
}
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infotype X){
	(*S).TOP++;
	(*S).T[(*S).TOP-1] = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
void Pop(Stack *S, infotype *X){
	*X = (*S).T[(*S).TOP-1];
	(*S).TOP--;
}
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

/* ********** Operator Tambahan ********* */
void ForcePush(Stack *S, infotype X){
	if (IsFull(*S)){
		infotype Y;
		infotype Z;
		address Count = (*S).TOP;
		Pop(S,&Y);
		while ((*S).TOP > 1){
			Pop(S,&Z);
			(*S).T[(*S).TOP] = Y;
			Y = Z;
		}
		(*S).TOP = Count-1;
	}
	Push(S,X);
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S mungkin penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1
        Apabila S penuh, buang element paling bawah dari S dan masukkan X sebagai TOP
        Contoh: S berisi a b c d e f g h i j, setelah melakukan ForcePush(S, "k")
        S berisi b c d e f g h i j k */
