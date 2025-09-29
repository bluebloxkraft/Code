known = [0, 1]

def fib(n):
    if len(known) >= n + 1:
        return known[n]
    else:
        x = fib(n - 1) + fib(n - 2)
        known.insert(n, x)
        return x

for i in range(100):
    print(fib(i), end = " ")
