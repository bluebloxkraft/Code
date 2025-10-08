print("This thing prints the binomial expansion of (x+y)^n")
n = int(input("Enter the value of n: "))

fac_known: {int: int} = {0: 1}

def fac(x: int) -> int:
    global fac_known
    if x not in fac_known:
        fac_known[x] = x * fac(x - 1)
    return fac_known[x]

C_known: {(int, int): int} = {}

def C(n: int, k: int) -> int:
    global C_known
    if (n, k) not in C_known:
        C_known[(n, k)] = int(fac(n) / fac(n - k) / fac(k))
    return C_known[(n, k)]
   
terms: [str] = []
for i in range(n + 1):
    terms.append(f"{C(n, i)} x^{n - i} y^{i}")

print("The expansion is:", " + ".join(terms))
