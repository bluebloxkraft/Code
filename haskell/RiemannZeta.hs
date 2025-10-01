import Data.Complex

zeta :: Float -> Float
zeta s = sum $ map (\n -> 1/(n**s)) [1..1000]
