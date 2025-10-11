for r in range(32):
    for g in range(32):
        for b in range(32):
            print(f"\033[38;2;{8 * r};{8 * g};{8 * b}mA\033[0m", end="")
