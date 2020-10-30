--NIM				: 18219036
--Nama				: Zachrandika Alif Syahreza
--Nama file		    : LuasSegitiga.hs
--Tanggal			: 10 September 2020
--Topik praktikum	: Haskell basic dan rekurens
--Deskripsi		    : luasSegitiga yang menerima masukan 2 buah bilangan real (float) a dan t dengan a = alas segitiga dan t = 
--                    tinggi segitiga (asumsikan: a > 0, t > 0) dan menghasilkan luas segitiga berdasarkan rumus: luas = ½ * a * t


module LuasSegitiga where

-- Defini dan Spesifikasi
luasSegitiga :: Float -> Float -> Float
-- program menerima input 2 buah bilangan real a dan t
-- asumsi a > 0 dan t > 0

-- Realisasi
luasSegitiga a t = 0.5 * a * t
