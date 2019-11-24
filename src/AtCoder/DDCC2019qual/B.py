N = int(input())
a_list = list(map(int, input().split()))

S = sum(a_list)
from itertools import accumulate
# a_list.index(0, 0)
acc = list(accumulate(a_list))

ans = float("inf")
for i in range(N):
    ans = min(ans, abs((S - acc[i]) - acc[i]))

print(ans)
