import sys

N, M = map(int, sys.stdin.readline().split())
a_list = list(map(int, sys.stdin.readline().split()))
items = []
for i in range(M):
    items.append(tuple(map(int, sys.stdin.readline().split())))

from heapq import *

que = []

for i in range(N):
    a = a_list[i]
    heappush(que, (-a, 1))

for b, c in items:
    heappush(que, (-c, b))

cnt = 0
ans = 0
while cnt < N:
    k, v = heappop(que)
    if cnt + v <= N:
        cnt += v
        ans += -(k * v)
    else:
        ans += -(k) * (N - cnt)
        cnt = N
print(ans)
