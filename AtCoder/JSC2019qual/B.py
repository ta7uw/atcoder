N, K = map(int, input().split())

a_list = list(map(int, input().split()))
mod = 10 ** 9 + 7

ans = 0
pre = []
from bisect import *

for i in range(N):
    a = a_list[i]
    for j in range(i + 1, N):
        b = a_list[j]
        if a > b:
            ans += (K + 1) * K // 2
            ans %= mod
    idx = bisect_left(pre, a)
    ans += idx * ((K - 1) * K // 2)
    ans %= mod
    insort_left(pre, a)
print(ans)
