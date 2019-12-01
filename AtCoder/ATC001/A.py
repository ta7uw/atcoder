import sys

sys.setrecursionlimit(10 ** 9)

H, W = map(int, input().split())
graph = [[] for _ in range(H)]
start = []
goal = []
visited = [[False for _ in range(W)] for _ in range(H)]
for i in range(H):
    tmp = list(input())
    if tmp.count("s") == 1:
        j = tmp.index("s")
        start = [i, j]
    if tmp.count("g") == 1:
        j = tmp.index("g")
        goal = [i, j]
    graph[i] = tmp


def search(x, y):
    if x < 0 or W <= x or y < 0 or H <= y or graph[y][x] == "#":
        return
    if visited[y][x]:
        return

    visited[y][x] = True

    search(x + 1, y)
    search(x - 1, y)
    search(x, y + 1)
    search(x, y - 1)


search(start[1], start[0])
if visited[goal[0]][goal[1]]:
    print("Yes")
else:
    print("No")
