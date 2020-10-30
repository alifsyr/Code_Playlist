module Kurs where

--DEFINIS DAN SPESIFIKASI
kurs  :: Int -> Char -> (Int, Int)
--menerima input masukan berupa nilai rupai dan charecter D,E,Y

--REALISASI
kurs  x y = if y == 'D' then ((div x 14700) , (x - (div x 14700) * 14700))
				else if y == 'E' then ((div x 17400) , (x - (div x 17400) * 17400))
				else ((div x 139) , (x - (div x 139) * 139))

