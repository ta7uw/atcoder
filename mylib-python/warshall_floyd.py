def warshall_floyd(graph):
    num_v = len(graph)
    for k in range(num_v):
        for i in range(num_v):
            for j in range(num_v):
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
    return graph
