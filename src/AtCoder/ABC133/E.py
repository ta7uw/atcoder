N, K = map(int, input().split())
from collections import defaultdict

graph = defaultdict(list)
for i in range(N - 1):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)

mod = 10 ** 9 + 7

import sys

sys.setrecursionlimit(10 ** 9)


def dfs(prev, now, graph):
    if prev == -1:
        mul = K - 1
    else:
        mul = K - 2

    if K < len(graph[now]):
        return 0
    else:
        tmp = 1
        for v in graph[now]:
            if v == prev:
                continue
            else:
                tmp *= mul
                mul -= 1
                tmp %= mod
                tmp *= dfs(now, v, graph)
                tmp %= mod
    return tmp


ans = K
ans *= dfs(-1, 0, graph)
print(ans % mod)
