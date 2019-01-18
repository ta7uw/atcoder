N = int(input())
ans = 0

for i in range(9):
    a = N // pow(10, i + 1)
    b = N % pow(10, i + 1)
    ans += a * pow(10, i)
    if b >= pow(10, i):
        ans += min(pow(10, i), b - pow(10, i) + 1)
print(ans)
