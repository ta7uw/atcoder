N = int(input())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))

ans = float("inf")

for i in range(N):
    for j in range(N):
        start = items[i][0]
        end = items[j][1]
        tmp = 0
        for a, b in items:
            tmp += abs(start - a)
            tmp += abs(a - b)
            tmp += abs(end - b)
        ans = min(ans, tmp)
print(ans)
