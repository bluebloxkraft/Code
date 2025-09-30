import System.IO

numRange = [1..100]

sumOfDigits :: Integer -> Integer
sumOfDigits 0 = 0
sumOfDigits x = (x `mod` 10) + sumOfDigits (x `div` 10)

isHarshad :: Integer -> Bool
isHarshad x = (x `mod` sumOfDigits x) == 0

harshads = filter isHarshad numRange

main = do
   print harshads
