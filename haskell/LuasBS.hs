--DEFINISI DAN SPESIFIKASI
luasBS :: Int -> Int

--REALISASI
luasBS x =
  if (x==1) then 1
  else
    luasBS(x-1) + (x*2-1)