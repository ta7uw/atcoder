N = int(input())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))
ans = 0
for a, b in items:
    ans += min(a // 2, b)
print(ans)
