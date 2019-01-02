def washall_floyd(graph):
    num_v = len(graph)
    for k in range(num_v):
        for i in range(num_v):
            for j in range(num_v):
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
    return graph


n, m, r = map(int, input().split())
r_list = list(map(int, input().split()))
graph = [[float("inf") for _ in range(n)] for _ in range(n)]
for i in range(m):
    a, b, c = map(int, input().split())
    graph[a - 1][b - 1] = c
    graph[b - 1][a - 1] = c

graph = washall_floyd(graph)
result = float("inf")
import itertools
permi = itertools.permutations(r_list)
for per in permi:
    r = 0
    start = per[0] - 1
    for p in per[1:]:
        end = p - 1
        r += graph[start][end]
        start = p - 1
    result = min(r, result)
print(result)
