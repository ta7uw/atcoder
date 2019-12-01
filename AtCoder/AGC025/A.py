N = int(input())
r = float("inf")
for i in range(1, N):
    A = i
    B = N - i
    a = 0
    b = 0

    while A >= 1:
        a += A % 10
        A /= 10

    while B >= 1:
        b += B % 10
        B /= 10

    if a + b <= r:
        r = a + b

print(int(r))
