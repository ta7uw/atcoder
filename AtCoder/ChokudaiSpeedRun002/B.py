N = int(input())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))

for a, b in items:
    print(a % b)
