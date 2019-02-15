r, c = map(int, input().split())
grid = []
for _ in range(r):
    grid.append(list(input()))
V = r * c
graph = [[] for i in range(V)]

for i in range(r):
    for j in range(c - 1):
        if not (grid[i][j] == grid[i][j + 1] == "."):
            continue
        tmp = i * c + j
        graph[tmp].append(tmp + 1)
        graph[tmp + 1].append(tmp)

for i in range(r - 1):
    for j in range(c):
        if not (grid[i][j] == grid[i + 1][j] == "."):
            continue
        tmp = i * c + j
        graph[tmp].append(tmp + c)
        graph[tmp + c].append(tmp)

cnt = 0
for i in range(r):
    for j in range(c):
        s = grid[i][j]
        if s == ".":
            cnt += 1

match = [-1] * V
used = [0] * V


def dfs(v):
    used[v] = 1
    for to in graph[v]:
        w = match[to]
        if w < 0 or (not used[w]) and dfs(w):
            match[v] = to
            match[to] = v
            return True
    return False


def bipartite_matching():
    global used
    ret = 0
    for v in range(V):
        if match[v] < 0:
            used = [0] * V
            if dfs(v):
                ret += 1
    return ret


print(cnt - bipartite_matching())
