import sys

sys.setrecursionlimit(10 ** 8)

N, M = map(int, input().split())
graph = [dict() for _ in range(N)]

for i in range(M):
    x, y = map(int, input().split())
    graph[y - 1][x - 1] = 1

dp = [0 for _ in range(N)]


def dfs(u):
    if dp[u] != 0:
        return dp[u]
    max_dis = 0
    for f in graph[u].keys():
        if max_dis < dfs(f) + 1:
            max_dis = dfs(f) + 1

    dp[u] = max_dis
    return dp[u]


for i in range(N):
    dfs(i)
print(max(dp))
