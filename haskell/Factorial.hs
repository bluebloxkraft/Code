import System.IO

factorial :: Integer -> Integer
factorial 0 = 1
factorial x = x * factorial (x - 1)

main = do
   putStr "Enter the number: "
   hFlush stdout -- NOTE: apparently this is required because putStr only puts the string into a buffer.
   input <- getLine
   let n = read input :: Integer
   putStrLn ("The factorial of the number is " ++ show (factorial n))
