H, W = map(int, input().split())
grid = []
for i in range(H):
    grid.append(input())

chance = []
for i, g in enumerate(grid):
    if g.count(".") == W:
        chance.append(i)

visit = [[False] * W for _ in range(H)]


def dfs(target, i, j):
    res = False
    if i == H or j == W:
        return False
    if visit[i][j] or grid[i][j] == "#":
        return False
    if j == target:
        return True
    visit[i][j] = True

    res |= dfs(target, i + 1, j)
    res |= dfs(target, i, j + 1)
    return res


visit2 = [[False] * W for _ in range(H)]


def dfs2(i, j):
    res = False
    if i == H or j == W:
        return False
    if visit2[i][j] or grid[i][j] == "#":
        return False
    if i == H - 1 and j == W - 1:
        return True
    visit2[i][j] = True

    res |= dfs2(i + 1, j)
    res |= dfs2(i, j + 1)
    return res


for c in chance:
    if dfs(c, 0, 0):
        f = True
        for j in range(W):
            if dfs2(c, j):
                print("Yay!")
                exit()

print(":(")
