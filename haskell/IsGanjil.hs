--DEFINISI dan SPESIFIKASI
isGanjil :: Int -> Bool

--REALISASI
isGanjil x =
  if ((mod x 2) == 0) then False
  else
    True
