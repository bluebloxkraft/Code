known: {int: str} = {0: "∅"}

def von_neumann(n: int) -> str:
    global known
    if n in known:
        return known[n]
    else:
        res = von_neumann(0)
        for i in range(1, n):
            res += f", {von_neumann(i)}"
        res = f"{{{res}}}"
        known[n] = res
        return res;

# test (omg it grows so fast, damn)
print(von_neumann(10))
