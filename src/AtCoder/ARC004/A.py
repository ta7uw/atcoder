N = int(input())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))

ans = 0
for x1, y1 in items:
    for x2, y2 in items:
        ans = max(ans, (abs(x1 - x2) ** 2 + abs(y1 - y2) ** 2) ** 0.5)
print(ans)
