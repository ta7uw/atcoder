N = int(input())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))
ans = 0
for a, b in items:
    ans = max(ans, a + b)
print(ans)
