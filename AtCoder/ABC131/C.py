A, B, C, D = map(int, input().split())

cnt = 0
from fractions import gcd


def lcm(x, y):
    return (x * y) // gcd(x, y)


c = B // C
c2 = A // C
if A % C == 0:
    c2 -= 1
d = B // D
d2 = A // D
if A % D == 0:
    d2 -= 1
t = B // lcm(C, D)
t2 = A // lcm(C, D)
if A % lcm(C, D) == 0:
    t2 -= 1

print(B - A + 1 - ((c - c2) + (d - d2) - (t - t2)))
