N = int(input())
a_list = list(map(int, input().split()))

now = 1
next_mis = -1
ans = 0
for i, a in enumerate(a_list):
    i += 1
    next_mis = max(next_mis, a)
    if next_mis <= i:
        ans += 1
        next_mis = -1
    else:
        now = next_mis
print(ans)
