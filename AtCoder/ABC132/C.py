N = int(input())
d_list = list(map(int, input().split()))

d_list.sort()
from bisect import bisect_right

ans = 0

for i in range(1, max(d_list)):
    idx = bisect_right(d_list, i)
    if N // 2 == idx:
        ans += 1
print(ans)
