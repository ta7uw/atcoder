from itertools import accumulate

N = int(input())
h_list = list(map(int, input().split()))

h_max = list(accumulate(h_list, max))
ans = 0
for h, m in zip(h_list, h_max):
    if m <= h:
        ans += 1
print(ans)
