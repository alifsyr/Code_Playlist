#include<stdio.h>
#include "point.h"
#include "math.h"

/* 18219050 */
/* Kevin Kencana */
/* 17 September 2020 */
/* Praktikum 1 Soal 3 */
/* program point.c adalah implementasi dari point.h */

int main() 
{
	POINT MakePOINT (float X, float Y) {
		POINT P;
		Absis(P) = X;
		Ordinat(P) = Y;
		return P;
	}
	void BacaPOINT (POINT * P) {
		float X;
		float Y;
		scanf("%f %f", &X, &Y);
		MakePOINT(X,Y);
	}
	void TulisPOINT (POINT P){
		printf("(%f,%f)\n", Absis(P), Ordinat(P));
	}
	boolean EQ (POINT P1, POINT P2) {
		if (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2)) {
			return true;
		}
		else {
			return false;
		}
	}
	boolean NEQ (POINT P1, POINT P2) {
		if (Absis(P1) != Absis(P2) || Ordinat(P1) != Ordinat(P2)) {
			return true;
		}
		else{
			return false;
		}
	}
	boolean IsOrigin (POINT P){
		if (Absis(P) == 0 && Ordinat(P) == 0){
			return true;
		}
		else {
			return false;
		}
	}
	boolean IsOnSbX (POINT P){
		if (Ordinat(P) == 0) {
			return true;
		} 
		else {
			return false;
		}
	}
	boolean IsOnSbY (POINT P) {
		if (Absis(P) == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	int Kuadran (POINT P) {
		if (IsOrigin(P) == false && IsOnSbX(P) == false && IsOnSbY(P) == false)  {
			if (Absis(P) > 0 && Ordinat(P) > 0) {
				printf("1\n");
			}
			else if (Absis(P) < 0 && Ordinat(P) > 0) {
				printf("2\n");
			}
			else if (Absis(P) < 0 && Ordinat(P) < 0) {
				printf("3\n");
			}
			else /* absis > 0 dan ordinat < 0*/ {
				printf("4\n");
			}
		}
	}
	POINT PlusDelta (POINT P, float deltaX, float deltaY){
		POINT Q;
		Q = P;
		Absis(Q) += deltaX;
		Ordinat(Q) += deltaY;
		return Q;
	}
	void Geser (POINT *P, float deltaX, float deltaY) {
		Absis(P) += deltaX;
		Ordinat(P) += deltaY;
	}
	float Jarak0 (POINT P){
		float jarak;
		jarak = sqrt(Absis(P)*Absis(P) + Ordinat(P)*Ordinat(P));
		return jarak;
	}
	float Panjang (POINT P1, POINT P2) {
		float panjang;
		panjang = sqrt((Absis(P1)-Absis(P2))*(Absis(P1)-Absis(P2)) + ((Ordinat(P1)-Ordinat(P2))*(Ordinat(P1)-Ordinat(P2))));
		return panjang;
	}

}
