H, W = map(int, input().split())
items = []
black = []
for i in range(H):
    tmp = list(input())
    for j in range(W):
        if tmp[j] == "#":
            black.append((i, j))
    items.append(tmp)

que = []
for b in black:
    que.append(b)

ans = 0
d4 = [(1, 0), (0, -1), (-1, 0), (0, 1)]
next_que = que
while len(que) != H * W:
    tmp = next_que
    next_que = []
    for b in list(tmp):
        x, y = b[0], b[1]
        for d in d4:
            dx = d[0]
            dy = d[1]
            if 0 <= x + dx <= H - 1 and 0 <= y + dy <= W - 1:
                tar = items[x + dx][y + dy]
                if tar == ".":
                    next_que.append((x + dx, y + dy))
                    que.append((x + dx, y + dy))
                    items[x + dx][y + dy] = "#"
    ans += 1
print(ans)
