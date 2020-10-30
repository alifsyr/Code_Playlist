--DEFINIS DAN SPESIFIKASI
isJamValid :: Int -> Int -> Int -> Bool

--REALISASI
isJamValid j m d =  if((j>0 && j<=23)&&(m>0 && m<=59)&&(d>0 && d<=59)) then True
                    else False
