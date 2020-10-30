--DEFINISI DAN SPESIFIKASI
deretSegitiga :: Int -> Int

--REALISASI
deretSegitiga n =
  if (n==1) then n
  else
    n + deretSegitiga(n-1)