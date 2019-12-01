N, K = map(int, input().split())
import math

ans = 0
for i in range(1, N + 1):
    if i >= K:
        ans += 1 / N
    else:
        tmp = math.ceil(math.log(K / i, 2))
        ans += (1 / N) * 0.5 ** tmp
print(ans)
