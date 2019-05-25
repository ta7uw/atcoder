N, M = map(int, input().split())
items = []
for i in range(M):
    items.append(tuple(map(int, input().split())))

ran = [0 for i in range(N+2)]
for l, r in items:
    ran[l-1] += 1
    ran[r] -= 1


for i in range(N+1):
    ran[i+1] += ran[i]

target = set()
for i, r in enumerate(ran):
    if r == M:
        target.add(i+1)
print(len(target))
