n = int(input())
t_list = [int(input()) for _ in range(n)]


def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)


def lcm(a, b):
    return a * b // gcd(b, a % b)


r = 1
for i in range(n):
    r = lcm(r, t_list[i])
print(r)
