--NIM				: 18219036
--Nama				: Zachrandika Alif Syahreza
--Nama file		    : SumKelipatanX.hs
--Tanggal			: 10 September 2020
--Topik praktikum	: Haskell basic dan rekurens
--Deskripsi		    : sumKelipatanX yang menerima masukan dua buah integer positif (integer > 0), misalnya m dan n, serta sebuah integer positif lain, yaitu x, 
--                    dan menghasilkan jumlah total bilangan kelipatan x di antara m dan n (m dan n termasuk) dengan menggunakan ekspresi rekursif.

module SumKelipatanX where

-- Definisi dan Spesifikasi
sumKelipatanX :: Int -> Int -> Int -> Int
-- menerima masukan dua buah integer positif (integer > 0), misalnya m dan n, serta sebuah integer positif lain, yaitu x.

-- Realisasi
sumKelipatanX m n x = if (mod m x)==0 then
						if m==n then m -- Basis
                        else m +(sumKelipatanX (m+1) n x) -- Rekurens
                     else if m==n then 0 -- Basis
					 else (sumKelipatanX (m+1) n x) -- Rekurens
