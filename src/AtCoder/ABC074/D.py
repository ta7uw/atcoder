def warshall_floyd(graph):
    num_v = len(graph)

    for k in range(num_v):
        for i in range(num_v):
            for j in range(num_v):
                if graph[i][j] > graph[i][k] + graph[k][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]
    return graph

N = int(input())
graph = [[float("inf") for _ in range(N)] for _ in range(N)]
for i in range(N):
    a_list = list(map(int, input().split()))
    for j in range(N):
        if i == j:
            continue
        graph[i][j] = a_list[j]
import copy
a_list = copy.deepcopy(graph)
w_graph = warshall_floyd(graph)
result = 0
for i in range(N):
    for j in range(i+1, N):
        if i == j:
            continue
        if w_graph[i][j] != a_list[i][j]:
            print(-1)
            exit()
        d = []
        for k in range(N):
            d.append(w_graph[i][k] + w_graph[j][k])
        if min(d) > w_graph[i][j]:
            result += w_graph[i][j]
print(result)
