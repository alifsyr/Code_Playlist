--DEFINIS DAN SPESIFIKASI
nilaiTengah :: Int -> Int -> Int -> Int
min3 :: Int -> Int -> Int -> Int
max3 :: Int -> Int -> Int -> Int

--Realisasi
max3 a b c =  
  if(a>b) && (a>c) then a
  else if (b>a) && (b>c) then b
  else c

min3 a b c =
  if(a<b) && (a<c) then a
  else if (b<a) && (b<c) then b
  else c

nilaiTengah a b c= (a+b+c)-(min3 a b c)-(max3 a b c)