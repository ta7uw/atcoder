N = int(input())
u_list = list(map(int, input().split()))

from collections import defaultdict

colors = defaultdict(int)
cnt = defaultdict(int)
max_length = 0
ans = 0
for i in range(1, N + 1):
    u = u_list[i - 1]
    cnt[colors[u]] -= 1
    colors[u] += 1
    cnt[colors[u]] += 1
    max_length = max(max_length, colors[u])

    ok = False
    if cnt[1] == i:
        ok = True
    elif cnt[i] == 1:
        ok = True
    elif cnt[1] == 1 and cnt[max_length] * max_length == i - 1:
        ok = True
    elif cnt[max_length - 1] * (max_length - 1) == i - max_length and cnt[max_length] == 1:
        ok = True
    if ok:
        ans = i
print(ans)
