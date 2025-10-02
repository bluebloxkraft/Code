known = {0: "∅"}

def von_neumann(n: int):
    global known
    if n in known:
        return known[n]
    else:
        str = von_neumann(0)
        for i in range(1, n):
            str += f", {von_neumann(i)}"
        str = "{" + str + "}"
        known[n] = str
        return str;

# test (omg it grows so fast, damn)
print(von_neumann(10))
