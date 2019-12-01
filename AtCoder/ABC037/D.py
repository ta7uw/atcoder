import sys
sys.setrecursionlimit(10**9)
h, w = map(int, input().split())
graph = [[] for _ in range(h)]
mod = 10**9+7
delta = [-1, 1]
for i in range(h):
    graph[i] = list(map(int, input().split()))


dp = [[0 for _ in range(w)] for _ in range(h)]

def dfs(x, y):
    if dp[x][y] != 0:
        return dp[x][y]
    res = 1
    for d in delta:
        if 0 <= x + d <= h-1:
            if graph[x][y] < graph[x+d][y]:
                res += dfs(x+d, y)
        if 0 <= y + d <= w-1:
            if graph[x][y] < graph[x][y+d]:
                res += dfs(x, y+d)
    res %= mod
    dp[x][y] = res
    return res
result = 0
for i in range(h):
    for j in range(w):
        result += dfs(i, j)
    result %= mod
print(result)