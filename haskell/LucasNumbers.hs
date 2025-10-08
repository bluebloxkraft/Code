lucas :: Integer -> Integer
lucas 0 = 2
lucas 1 = 1
lucas x = lucas (x - 1) + lucas (x - 2)
