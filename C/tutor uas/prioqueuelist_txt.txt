#include "prioqueuelist.h"

void Alokasi(address *P, ElType X, int Priority)
{
  /* Node *N = malloc(1 * sizeof (Node));
  P = &N; */ 
  *P =(Node *) malloc ( 1 * sizeof(Node));
  if (P != Nil) {
    Info(*P) = X;
    Next(*P) = Nil;
    Prio(*P) = Priority;
  }
}

void Dealokasi(address P)
{
    free(P);
}

boolean IsEmpty(PrioQueue Q)
{
    return (Head(Q) == Nil);
}

int NBElmt(PrioQueue Q)
{
  int count = 0;
  address P;

  if (!IsEmpty(Q)) {
    P = Head(Q);
    while (P != Nil) {
      count++;
      P = Next(P);
    }
  }
  return count;
}

void CreateEmpty(PrioQueue *Q)
{
    Head(*Q) = Nil;
}

void Enqueue(PrioQueue *Q, ElType X, int Priority)
{
    address P;
    Alokasi(&P,X,Priority);
    if (P != Nil){
        if (IsEmpty(*Q)){
            Head(*Q) = P;
        }else
        {
            boolean found = false;
            address Prec;
            Prec = Head(*Q);
            if (Prio(Prec) > Prio(P)){
                Next(P) = Prec;
                Head(*Q) = P;
            }else{ /*{Ini aku inget agak bingung gitu, dia pengecekan kondisi antara di while nya atau di dalem loop*/
                while (!found && (Next(Prec) != Nil)){
                    if (Prio(Next(Prec)) > Prio(P)){
                        found = true;
                    }else
                    {
                        Prec = Next(Prec);
                    }
                }
                Next(P) = Next(Prec);
                Next(Prec) = P;
            }
        }
    }
    /* Anggapannya prioqueue menempatkan elemen dengan prioritas yang paling besar, paling belakang */
    /* Sehingga semakin besar priority suatu elemen, akan semakin jauh dari Head(Q) penempatannya */
    /* Dengan Head(Q) selalu memiliki prioritas paling kecil dalam suatu queue */
}

void Dequeue(PrioQueue *Q, ElType *X){
    address P = Head(*Q);
    *X = Info(P);
    Head(*Q) = Next(Head(*Q));
    Dealokasi(P);
    /*Di pembahasan pakenya  *X = InfoHead(*Q)*/
}