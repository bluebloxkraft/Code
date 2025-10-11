print("This thing prints the binomial expansion of (x+y)^n")
n = int(input("Enter the value of n: "))

fac_known: {int: int} = {0: 1}

def fac(x: int) -> int:
    if x not in fac_known:
        fac_known[x] = x * fac(x - 1)
    
    return fac_known[x]

C_known: {(int, int): int} = {}

def C(n: int, k: int) -> int:
    if k > n/2:
        return C(n, n - k)
    if (n, k) not in C_known:
        C_known[(n, k)] = int(fac(n) / fac(n - k) / fac(k))
    
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


# this prints the LaTeX code/markup/whatever you wanna call it for the expansion
# only called in the commented print in the last line. so you can uncomment that line to get this thing's output too
def gen_latex_markup() -> str:
    terms: [str] = []

    for i in range(n + 1):
        terms.append(f"{C(n, n - i)} x^{{{n - i}}} y^{{{i}}}")
    return " + ".join(terms)

# MAIN RUNNING CODE (below)

def main():
   terms: [str] = []
   
   for i in range(n + 1):
      # terms.append(f"{C(n, i)} x^{n - i} y^{i}")
      terms.append(get_term_formatted(C(n, i), n - i, i))
   
   print("The expansion is:", " + ".join(terms))
 # print("The LaTeX format is: ", gen_latex_markup())

main()
