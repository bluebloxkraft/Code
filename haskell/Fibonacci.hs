import System.IO

fib :: Integer -> Integer
fib 0 = 1
fib 1 = 1
fib n = (fib $ n - 1) + (fib $ n - 2)

main = do
   putStr "Enter a number: "
   hFlush stdout
   input <- getLine
   let n = read input :: Integer
   print $ fib n
