module ListOfCharacter where

isEmpty :: [Char] -> Bool
-- isEmpty(li) true jika list of integer li kosong
-- REALISASI
isEmpty li = null li;

isOneElmt :: [Char] -> Bool
--isOneElmt(li) true jika list of integer li hanya
--mempunyai satu elemen
--REALISASI
isOneElmt li = (length li) == 1;

konso:: Char ->  [Char] -> [Char]
-- konso(e,l) menghasilkan sebuah list dari e (sebuah
-- elemen) dan l (list of elemen),
-- dengan e sebagai elemen pertama: e o l --> l'
-- REALISASI
konso e l = [e] ++ l

konsDot:: [Char] -> Char -> [Char]
-- kons Dot (l,e) menghasilkan sebuah list dari l (list of
-- elemen) dan e (sebuah elemen),
-- dengan e sebagai elemen terakhir: l e -->
-- REALISASI
konsDot l e = l ++ [e]

konkat :: [Char] -> [Char] -> [Char]

konkat lc1 lc2=
  if (isEmpty lc1) && (isEmpty lc2) then []
  else if (isEmpty lc1) && not(isEmpty lc2) then lc2
  else if not(isEmpty lc1) && (isEmpty lc2) then lc1
  else
    (konso (head lc1) (konkat(tail lc1)lc2))