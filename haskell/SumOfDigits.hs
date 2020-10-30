--DEFINIS DAN SPESIFIKASI
sumDigits :: Int-> Int

--REALISASI
sumDigits x =
  if (x == 0) then 0
  else
    mod x 10 + sumDigits(div x 10)