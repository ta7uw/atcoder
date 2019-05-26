N = int(input())
items = []
for i in range(N):
    s, p = input().split()
    items.append((s, int(p), i))

items = sorted(items, key=lambda x: (x[0], -x[1]))

for s, p, i in items:
    print(i + 1)
