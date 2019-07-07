N, D = map(int, input().split())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))

res = set()
for i in range(1000):
    res.add(i ** 2)

ans = 0
for i in range(N):
    a = 0
    for j in range(i + 1, N):
        tmp = 0
        for k in range(D):
            y = items[i][k]
            x = items[j][k]
            tmp += abs(y - x) ** 2
        a = tmp
        if a in res:
            ans += 1
print(ans)
