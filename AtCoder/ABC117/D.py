N, K = map(int, input().split())
A = list(map(int, input().split()))

b = [0] * 41
for a in A:
    for k in range(41):
        if a & (1 << k):
            b[k] += 1

x = 0
for k in range(40, -1, -1):
    if x + (1 << k) > K:
        continue
    if b[k] < (N + 1) // 2:
        x += (1 << k)

ans = 0
for a in A:
    ans += x ^ a
print(ans)
