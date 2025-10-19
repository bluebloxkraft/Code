x = int(input("Enter a number: "))

known: {int: str} = {0: "∅"}

def von_neumann(n: int) -> str:
    if n not in known:
        elems: [str] = []
        for i in range(n):
            elems.append(von_neumann(i))
        known[n] = "{" + ", ".join(elems) + "}" # i think, in this case, simply concatenating the curly brackets is more readable than f-strings
    return known[n]

# test (omg it grows so fast, damn)
print(von_neumann(x))
