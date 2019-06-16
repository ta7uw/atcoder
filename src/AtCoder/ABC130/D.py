N, K = map(int, input().split())
a_list = list(map(int, input().split()))

ans = 0

from itertools import accumulate
from bisect import bisect_left

a_list.insert(0, 0)
acc = list(accumulate(a_list))

for a in acc:
    idx = bisect_left(acc, K + a)
    if idx >= 1:
        ans += (N - idx + 1)
print(ans)
