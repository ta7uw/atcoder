N = int(input())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))

items = sorted(items, key=lambda x: x[1])

now = 0
for k, v in items:
    if now + k <= v:
        now += k
        continue
    else:
        print("No")
        exit()
print("Yes")
