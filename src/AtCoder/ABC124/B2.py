N = int(input())
h_list = list(map(int, input().split()))
from itertools import accumulate

h_max = list(accumulate(h_list, max))
ans = 0
for i in range(N):
    tmp = h_max[i]
    h = h_list[i]
    if tmp <= h:
        ans += 1

print(ans)
