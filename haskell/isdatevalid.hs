--DEFINISI DAN SPESIFIKASI
isKabisat :: Int -> Bool
isDateValid :: Int -> Int -> Int -> Bool

--REALISASI
isKabisat y =
  if (mod y 400==0) then True
  else if (mod y 4==0) then True
  else if (mod y 100==0) then False
  else False

isDateValid d m y =
  if (d>=1 && d<=31) && (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) then True
  else if (not(m==2)) then
    if (d>=1 && d<=31) then True
    else False
  else if (m==2) then
    if(d>=1 && d<=29) &&(not(isKabisat y)) then True
    else if (d>=1 && d<=28) then True
    else False
  else
    False