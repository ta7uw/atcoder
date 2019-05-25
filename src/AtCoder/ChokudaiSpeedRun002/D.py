N = int(input())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))
ans = 0
for a, b in items:
    ans += max(a, b)
print(ans)
