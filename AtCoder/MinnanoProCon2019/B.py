from collections import defaultdict

items = defaultdict(int)
for i in range(3):
    a, b = tuple(map(int, input().split()))
    items[a] += 1
    items[b] += 1

for k, v in items.items():
    if v >= 3:
        print("NO")
        exit()
print("YES")
