N = int(input())
import sys

graph = [dict() for _ in range(N)]

for i in range(N - 1):
    u, v, w = map(int, sys.stdin.readline().split())
    graph[u - 1][v - 1] = w
    graph[v - 1][u - 1] = w

color = [-1] * N

import sys

sys.setrecursionlimit(10 ** 9)


def dfs(i, col):
    color[i] = col
    for k, v in graph[i].items():
        if color[k] == -1:
            if v % 2 == 0:
                dfs(k, col)
            else:
                dfs(k, 1 - col)


dfs(0, 1)

for c in color:
    print(c)
