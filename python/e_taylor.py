import sys

sys.set_int_max_str_digits(100000)

e = 1
fac = 1

for n in range(1, int(input("no. of terms - 1: "))):
    fac *= n
    e += 1/fac

print(e)
