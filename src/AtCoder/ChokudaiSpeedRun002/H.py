N = int(input())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))

for a, b in items:
    if a == b:
        print(-1)
        continue
    max_num = max(a, b)
    min_num = min(a, b)

    print(max_num - min_num)
