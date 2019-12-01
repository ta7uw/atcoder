N, M = map(int, input().split())
p_list = [int(input()) for _ in range(N)]

from bisect import *

ans = 0

p_list.append(0)

two = set()
for p1 in p_list:
    for p2 in p_list:
        two.add(p1 + p2)
two = sorted(two)
for t in two:
    if t <= M:
        idx = bisect_right(two, M - t)
        ans = max(ans, t + two[idx - 1])

print(ans)
