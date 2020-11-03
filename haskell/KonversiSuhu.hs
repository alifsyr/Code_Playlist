#NIM  18219001
#Nama Dimas Farhan Anshari
#Tanggal 08/10/2020
#Topik praktikum KONVERSISUHU
#Deskripsi

module KonversiSuhu where
-- DEFINISI DAN SPESIFIKASI
konversiSuhu :: Float -> (Float -> Float) -> Float
{- KonversiSuhu(t,f) dengan T merepresentasikan suhu dalam  derajat tertentu dan fungsi f yang merupakan
fungsi konversi suhu, menghasilkan konversi t ke suhu pada derajat tertentu berdasarkan fungsi f. -}

konversiSuhu t f=
  if (t == 0) then f(0)
  else
    f(t)