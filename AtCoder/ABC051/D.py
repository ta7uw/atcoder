from scipy.sparse.csgraph import floyd_warshall

N, M = map(int, input().split())

inf = float("inf")
graph = [[inf for _ in range(N)] for _ in range(N)]
edge = []
for i in range(M):
    a, b, c = map(int, input().split())
    graph[a - 1][b - 1] = c
    graph[b - 1][a - 1] = c
    edge.append([a - 1, b - 1])
w_graph = floyd_warshall(graph)

count = 0
for e in edge:
    e_s = e[0]
    e_e = e[1]
    used = False
    for i in range(N):
        if w_graph[i][e_e] == w_graph[i][e_s] + graph[e_e][e_s]:
            used = True
    if not used:
        count += 1

print(count)
