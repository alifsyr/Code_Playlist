#NIM  18219001
#Nama Dimas Farhan Anshari
#Tanggal 08/10/2020
#Topik praktikum Menghitung Pajak makanan
#Deskripsi

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

pajakMakanan :: [Char] -> [Int] -> [Char]

pajakMakanan lc li=
  if (isEmpty lc) && (li == []) then []
  else  if ((((fromIntegral(head li))*(10/100))+((fromIntegral(head li))) <= 200) then (konso(head lc)(pajakMakan (tail lc) (tail li)))
  else
    pajakMakanan (tail lc) (tail li)