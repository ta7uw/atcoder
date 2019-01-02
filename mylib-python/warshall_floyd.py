def warshall_floyd(graph):
    num_v = len(graph)
    for k in range(num_v):
        for i in range(num_v):
            for j in range(num_v):
                if graph[i][j] > graph[i][k] + graph[k][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]
    return graph

"""
from scipy.sparse.csgraph import floyd_warshall
w_graph = floyd_warshall(graph, directed=False)
"""