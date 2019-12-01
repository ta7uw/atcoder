H, W = map(int, input().split())
s_list = []
for i in range(H):
    s = list(input())
    s_list.append(s)

dp = [[0 for _ in range(W)] for _ in range(H)]
dp[0][0] = 1
mod = 10 ** 9 + 7
for i in range(H):
    for j in range(W):
        if s_list[i][j] == "#":
            continue
        if i + 1 < H and s_list[i + 1][j] == ".":
            dp[i + 1][j] += dp[i][j] % mod
        if j + 1 < W and s_list[i][j + 1] == ".":
            dp[i][j + 1] += dp[i][j] % mod
print(dp[H - 1][W - 1] % mod)

