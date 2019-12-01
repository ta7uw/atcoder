N = int(input())


def make_divisors(n):
    divisors = []
    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n // i)

    return divisors


divisors = make_divisors(N)
ans = 0
for d in divisors:
    t = d - 1
    if t != 0 and N % t == N // t:
        ans += t
print(ans)

