
-- No 1a
ubahArah :: Int->Int->Int
ubahArah s r =
	let hasil = r + s
	in 
		if hasil>=360 then hasil-360 
		else if hasil<0 then hasil+360 
		else hasil

-- No 1b
pangkat :: Int->Int->Int
pangkat a b
 | b == 0 = 1
 | otherwise = a * pangkat a (b-1)


konso :: Int -> [Int] -> [Int]
konso e li = [e] ++ li

konsDot :: [Int] -> Int -> [Int]
konsDot li e = li ++ [e]

isEmpty :: [Int] -> Bool
isEmpty li = null li

isOneElmt :: [Int] -> Bool
isOneElmt li = (length li) == 1

konsoF :: Float -> [Float] -> [Float]
konsoF e li = [e] ++ li

konsDotF :: [Float] -> Float -> [Float]
konsDotF li e = li ++ [e]

isEmptyF :: [Float] -> Bool
isEmptyF li = null li

isOneElmtF :: [Float] -> Bool
isOneElmtF li = (length li) == 1

-- No 2

isAllGanjil :: [Int] -> Bool
{- isAllGanjil l mengembalikan true apabila seluruh elemen l adalah bilangan ganjil.
Fungsi mengembalikan true jika l adalah list kosong -}
isAllGanjil l
 | isEmpty l = True
 | otherwise =
 	if (mod (head l) 2 /= 0) then isAllGanjil (tail l)
 	else False

getSmallest :: [Int] -> Int
{- getSmallest l mengembalikan elemen terkecil di l. Prekondisi: l tidak kosong. -}
getSmallest l
 | isOneElmt l = head l
 | otherwise =
 	let smallest = getSmallest (tail l)
 	in
 		if head l < smallest then head l
 		else smallest

delElement :: Int -> [Int] -> [Int]
{- delElement x l mengembalikan list l dengan elemen x yang telah dihapus dari l.
Jika x bukan elemen l, maka fungsi mengembalikan l semula.
Prekondisi: elemen l unik (setiap elemen hanya muncul 1 kali). -}
delElement x l
 | isEmpty l = []
 | otherwise =
 	if x/=head l then konso (head l) (delElement x (tail l))
 	else delElement x (tail l)

sortList :: [Int] -> [Int]
{- sortList l mengembalikan hasil pengurutan list l hingga elemen-elemennya terurut membesar.
Prekondisi: l tidak kosong dan semua elemennya unik. -}
sortList l
 | isOneElmt l = l
 | otherwise =
 	let m = getSmallest (tail l)
 	in
 		if head l<=m then konso (head l) (sortList (tail l))
 		else konso m (sortList (delElement m l))

offsetList :: (Float->Float) -> (Float->Float) -> Float -> Float -> [Float]
offsetList f g a b
 | a > b = []
 | otherwise =
 	konsoF (f a) offsetList f g (g a) b

