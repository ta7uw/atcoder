H, W = map(int, input().split())

grid = [[0] * W for _ in range(H)]
visited = [[False] * W for _ in range(H)]

start = ()
for i in range(H):
    tmp = input()
    for j in range(W):
        grid[i][j] = tmp[j]
        if tmp[j] == "s":
            start = (i, j, 0)
from collections import deque

que = deque()
que.append(start)
ans = False

while len(que) >= 1:
    q = que.popleft()
    for i, j in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
        h = q[0] + i
        w = q[1] + j
        if 0 <= h < H and 0 <= w < W:
            if visited[h][w] or q[2] >= 3:
                continue
            if grid[h][w] == ".":
                visited[h][w] = True
                que.appendleft((h, w, q[2]))
            if grid[h][w] == "#":
                visited[h][w] = True
                que.append((h, w, q[2] + 1))
            if grid[h][w] == "g":
                ans = True

print("YES" if ans else "NO")
