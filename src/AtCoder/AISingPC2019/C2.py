import sys

sys.setrecursionlimit(10 ** 9)

H, W = map(int, input().split())
s_list = []
for i in range(H):
    s_list.append(input())
check = [[False for _ in range(W)] for _ in range(H)]
move_x = [1, 0, -1, 0]
move_y = [0, 1, 0, -1]


def dfs(i, j):
    check[i][j] = True

    if s_list[i][j] == "#":
        cnt[0] += 1
    else:
        cnt[1] += 1

    for m in range(4):
        next_i = i + move_y[m]
        next_j = j + move_x[m]
        if 0 <= next_i < H and 0 <= next_j < W and s_list[i][j] != s_list[next_i][next_j] \
                and not check[next_i][next_j]:
            dfs(next_i, next_j)


ans = 0
for i in range(H):
    for j in range(W):
        cnt = [0] * 2
        dfs(i, j)
        ans += cnt[0] * cnt[1]
print(ans)
