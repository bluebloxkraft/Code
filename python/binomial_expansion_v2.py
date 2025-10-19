print("Binomial expansion! Yay!")
x = int(input("Enter a number: "))

C_known: {(int, int): int} = {0: 0}

def C(n: int, k: int) -> int:
    if k == 0:
        return 1
    if k > n/2:
        return C(n, n-k)
    if (n, k) not in C_known:
        res = 1
        for i in range(k+1):
            res *= (n - i)/(i + 1)
        C_known[(n, k)] = int(res)
    return C_known[(n, k)]

def superscript_num(n: int) -> str:
        if n == 1:
            return ""
        return str(n).replace("0", "⁰").replace("1", "¹").replace("2", "²").replace("3", "³").replace("4", "⁴").replace("5", "⁵").replace("6", "⁶").replace("7", "⁷").replace("8", "⁸").replace("9", "⁹")

def get_term_formatted(c: int, a: int, b: int) -> str:
    res = ""

    if c != 1:
        res = str(c)
    if a != 0:
        res += f"x{superscript_num(a)}"
    if b != 0: 
        res += f"y{superscript_num(b)}"
    
    return res    

def main():
   terms: [str] = []
   
   for i in range(x + 1):
      terms.append(get_term_formatted(C(x, i), x - i, i))
   
   print(f"The expansion of {x} is:", " + ".join(terms))

main()
