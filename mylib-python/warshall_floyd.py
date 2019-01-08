def warshall_floyd(graph):
    num_v = len(graph)
    for k in range(num_v):
        for i in range(num_v):
            for j in range(num_v):
                if graph[i][j] > graph[i][k] + graph[k][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]
    return graph


def faster_warhsall_floyd(graph):
    num_v = len(graph)
    for i in range(num_v):
        for j, c2 in enumerate(row[i] for row in graph):
            for k, (c1, c3) in enumerate(zip(graph[j], graph[i])):
                if c1 > c2 + c3:
                    graph[j][k] = c2 + c3
    return graph


"""
from scipy.sparse.csgraph import floyd_warshall
w_graph = floyd_warshall(graph, directed=False)
"""
