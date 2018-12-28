n = int(input())
graph = [dict() for _ in range(n)]

for i in range(n - 1):
    a, b, c = map(int, input().split())
    graph[a - 1][b - 1] = c
    graph[b - 1][a - 1] = c

q, k = map(int, input().split())
xy = []
for i in range(q):
    x, y = map(int, input().split())
    xy.append([x - 1, y - 1])
depth = [0 for _ in range(n)]
prev = [False for _ in range(n)]
depth[k - 1] = 0

import sys

sys.setrecursionlimit(10 ** 6)


def dfs(now, prev, cost, graph, depth):
    depth[now] = cost
    for k, v in graph[now].items():
        if k == prev:
            continue
        dfs(k, now, cost + v,  graph, depth)
    return depth


depth = dfs(k - 1, -1, 0, graph, depth)
for x, y in xy:
    print(depth[x] + depth[y])
