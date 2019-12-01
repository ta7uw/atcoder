n, m = map(int, input().split())
graph = [[] for _ in range(n)]
for i in range(m):
    x, y = map(int, input().split())
    graph[x-1].append(y-1)
    graph[y-1].append(x-1)

result = 1
for i in range(1<<n):
    count = 0
    h = 1
    for j in range(n):
        if (i >> j & 1) == 0:
            continue
        count += 1
        for k in range(j+1, n):
            if (i >> k & 1) == 0:
                continue
            if k not in graph[j]:
                h = 0
    if h >= 1:
        result = max(result, count)
print(result)