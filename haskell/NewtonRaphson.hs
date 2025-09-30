deltaX :: Float
deltaX = 1/(10^5)

-- the function; f(x)
f :: Float -> Float
f x = x^2 - x - 1

-- the derivative of f evaluated at x, id est f'(x)
slope :: Float -> Float
slope x = (f (x + deltaX) - f x) / deltaX

-- the algorithm; n is the number of iterations, g is the starting guess
newton :: Float -> Float -> Float
newton 1 x = x - (f x) / (slope x)
newton n g = newton (n - 1) (g - (f g) / (slope g))
