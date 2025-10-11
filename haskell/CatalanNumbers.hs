import System.IO

catalan :: Integer -> Integer
catalan 0 = 1
catalan n = sum $ map (\i -> (catalan i) * (catalan $ n - i - 1))[0..n-1]

main = do
   putStr "Enter a number: "
   hFlush stdout
   input <- getLine
   let n = read input :: Integer
   print $ catalan n
