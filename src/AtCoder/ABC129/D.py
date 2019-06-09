H, W = map(int, input().split())
s_list = [input() for _ in range(H)]

yoko = [[0] * W for _ in range(H)]
tate = [[0] * H for _ in range(W)]

for i in range(H):
    S = s_list[i]
    for j in range(W):
        s = S[j]
        if s == "#":
            continue
        else:
            yoko[i][j] += 1
    for j in range(W):
        if yoko[i][j] == 1 and j > 0:
            yoko[i][j] += yoko[i][j - 1]
    for j in range(W - 1, -1, -1):
        if yoko[i][j] != 0 and j - 1 >= 0 and yoko[i][j - 1] != 0:
            yoko[i][j - 1] = yoko[i][j]
for j in range(W):
    for i in range(H):
        s = s_list[i][j]
        if s == "#":
            continue
        else:
            tate[j][i] += 1
    for i in range(H):
        if tate[j][i] == 1 and i > 0:
            tate[j][i] += tate[j][i - 1]
    for i in range(H - 1, -1, -1):
        if tate[j][i] != 0 and i - 1 >= 0 and tate[j][i - 1] != 0:
            tate[j][i - 1] = tate[j][i]

ans = 0
for i in range(H):
    for j in range(W):
        ans = max(ans, tate[j][i] + yoko[i][j] - 1)
print(ans)
