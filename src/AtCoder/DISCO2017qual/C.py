from collections import defaultdict

N, C = map(int, input().split())
l_list = [int(input()) for i in range(N)]

ans = 0
l_list.sort()
used = defaultdict(int)
i = 0
for l in sorted(l_list, reverse=True):
    if used[l] >= 1:
        used[l] -= 1
        continue
    b = l_list[i]

    if l + b + 1 <= C:
        ans += 1
        used[l_list[i]] += 1
        i += 1
    else:
        ans += 1
print(ans)
