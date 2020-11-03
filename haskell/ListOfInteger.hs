module ListOfInteger where

isEmpty :: [Int] -> Bool
-- isEmpty(li) true jika list of integer li kosong
-- REALISASI
isEmpty li = null li

isOneElmt :: [Int] -> Bool
--isOneElmt(li) true jika list of integer li hanya
--mempunyai satu elemen
--REALISASI
isOneElmt li = (length li) == 1

konso:: Int ->  [Int] -> [Int]
-- konso(e,l) menghasilkan sebuah list dari e (sebuah
-- elemen) dan l (list of elemen),
-- dengan e sebagai elemen pertama: [ e, ... ]
-- REALISASI
konso e l = [e] ++ l

konsDot:: [Int] -> Int -> [Int]
-- kons Dot (l,e) menghasilkan sebuah list dari l (list of
-- elemen) dan e (sebuah elemen),
-- dengan e sebagai elemen terakhir: [ ... , e]
-- REALISASI
konsDot l e = l ++ [e]

nbElmt :: [Int] -> Int

nbElmt l=
  if (isEmpty l) then 0
  else if (isOneElmt l) then 1
  else
    1 + nbElmt (tail l)

isEqual :: [Int] -> [Int] -> Bool

isEqual l1 l2=
  if (isEmpty l1) && (isEmpty l2) then True 
  else if (isEmpty l1) && not (isEmpty l2) then False 
  else if not (isEmpty l1) && (isEmpty l2) then False
  else
    (head l1==head l2) && (isEqual (tail l1)(tail l2))

maxList :: [Int] -> Int

maxList l=
  if isOneElmt l then head l
  else
    (max (head l) (maxList (tail l)))