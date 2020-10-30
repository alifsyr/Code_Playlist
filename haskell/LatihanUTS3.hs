
{- delAllX l x mengembalikan sebuah list l1 dan integer n, dengan l1 memuat elemen-elemen l
setelah elemen bernilai x dihapus dan n memuat jumlah kemunculan elemen bernilai x pada l.
Contoh: delAllX [3,2,6,2,3] 3 = ([2,6,2],2); delAllX [] 3 = ([],0) -}
{-delAllX l x
 | isEmpty l = ([],0)
 | otherwise =
 	let (l1,n) = delAllX (tail l) x --pokoknya ini hasil
 	in -- terus itu hasil mau diapain
 		(if head l/=x then konso (head l) (l1) else l1
 		,(if head l==x then 1 else 0)+n)

splitListIF :: [Int] -> (Int->Bool) -> ([Int],[Int])
splitListIF l f
 | isEmpty l = ([],[])
 | otherwise =
 	let (l1,l2) = splitListIF (tail l) f
 	in
 		(if (f (head l)) then konso (head l) l1 else l1,
 		if (f (head l)) then l2 else konso (head l) l2)
-}
trunc l i = if l ==[] || i == o then []
			else ([head l] ++ (trunc (tail l) (i-1) ))
