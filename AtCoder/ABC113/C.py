N, M = map(int, input().split())

shi_map = []

for i in range(M):
    p, y = map(int, input().split())
    shi_map.append([i, p, y])

shi_map = sorted(shi_map, key=lambda x: (x[1], x[2]))

result = {}
shi_count = {}
for i, p, y in shi_map:

    if p in shi_count:
        c = shi_count[p]
        count = c + 1
        shi_count[p] = count
    else:
        shi_count[p] = 1
        count = 1
    result[i] = [p, count]
result = list(sorted(result.items(), key=lambda x: x[0]))

for i, p in result:

    p2 = str(p[0]).zfill(6)

    y = str(p[1]).zfill(6)
    r = p2+y
    print(r)
