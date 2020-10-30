countBill :: Int-> Int -> Int -> Int 

countKemunculanX a x =
    if a <= x then
        if a == x then 1
        else 0
    else if mod a 10 == x then 1 + (countKemunculanX(div a 10) x)
    
    

countBill a b x =
    if a == b then
        if a == x then 1
        else 0
    else if