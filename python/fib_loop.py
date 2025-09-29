import sys

sys.set_int_max_str_digits(100000)

def fib(n):
    f1 = 0
    f2 = 1
    fn = 1
    if n == 0:
        return 0
    for i in range(n):
        fn = f1 + f2
        f1 = f2
        f2 = fn
    return fn

print(fib(int(input("num: "))))
