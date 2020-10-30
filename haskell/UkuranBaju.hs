--NIM				: 18219036
--Nama				: Zachrandika Alif Syahreza
--Nama file		    : UkuranBaju.hs
--Tanggal			: 10 September 2020
--Topik praktikum	: Haskell basic dan rekurens
--Deskripsi		    : fungsi ukuranBaju yang menerima masukan 2 buah integer positif, misalnya t (tinggi badan dalam cm) dan b (berat badan dalam kg) 
--                    dan menghasilkan kode ukuran baju (1 adalah M, 2 adalah L, 3 adalah XL) atau kode 4 adalah untuk yang tidak mendapatkan kaos.


module UkuranBaju where

-- Defini dan Spesifikasi
ukuranBaju :: Int -> Int -> Int
-- program menerima input 2 buah bilangan real a dan t
-- asumsi a > 0 dan t > 0

-- Realisasi
ukuranBaju t b | (t <= 150 && b<10000) = 1
               | (t>170 && b<=60) = 2
               | (t>150 && t<=170 && b<=80) = 2
               | (t>150 && t<=170 && b>80) = 3
               | (t>170 && b>60 && b<=80) = 3
               | otherwise = 4