T = int(input())
ans = []
from itertools import accumulate
for t in range(T):
    n = int(input())
    t_list = list(map(int, input().split()))
    last = list(accumulate(reversed(t_list), min))
    cnt = 0
    for i in range(n):
        if t_list[n-1-i] > last[i]:
            cnt += 1
    ans.append(cnt)

for a in ans:
    print(a)
