from itertools import accumulate
from bisect import bisect_left, bisect_right

N, Q = map(int, input().split())
x_list = list(map(int, input().split()))
items = []
for _ in range(Q):
    items.append(tuple(map(int, input().split())))

x_acc = list(accumulate(x_list)) + [0]
for item in items:
    c, d = item
    ans = 0
    i = bisect_left(x_list, c - d)
    j = bisect_left(x_list, c)
    k = bisect_left(x_list, c + d)
    ans += c * (j - i) - (x_acc[j - 1] - x_acc[i - 1])
    ans += x_acc[k - 1] - x_acc[j - 1] - c * (k - j)
    ans += d * (N - k + i)
    print(ans)
