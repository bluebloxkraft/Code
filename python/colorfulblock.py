SIZE = 20
COLORDELTA = 16

for r in range(0, 0xFF, COLORDELTA):
    for g in range(0, 0xFF, COLORDELTA):
        for b in range(0, 0xFF, COLORDELTA):
            print(f"\033[H\033[48;2;{r};{g};{b}m")
            print(*(["  "*SIZE]*SIZE), sep="\n")
