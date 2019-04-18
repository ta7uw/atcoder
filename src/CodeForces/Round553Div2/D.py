N = int(input())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))

m = {}
for i, item in enumerate(items):
    a, b = item
    m[i] = a - b

m = sorted(m.items(), key=lambda x: -x[1])

ans = 0
i = 0
for k, _ in m:
    a, b = items[k]
    ans += a * i + b * (N - i - 1)
    i += 1
print(ans)
