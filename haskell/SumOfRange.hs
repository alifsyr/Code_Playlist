module SumOfRange where

sumOfRange :: Int -> Int -> Int

sumOfRange a b = if a == b then a
                 else a + (sumOfRange  b)