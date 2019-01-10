H, W, K = map(int, input().split())

dp = [[0 for _ in range(W)] for _ in range(H + 1)]

dp[0][0] = 1

for i in range(1, H + 1):
    for j in range(W):
        for k in range(2 ** (W - 1)):
            if bin(k).count("11") >= 1:
                continue
            if j + 1 <= W - 1 and (k >> j) & 1:
                dp[i][j] += dp[i - 1][j + 1]
            elif j - 1 >= 0 and (k >> (j - 1)) & 1:
                dp[i][j] += dp[i - 1][j - 1]
            else:
                dp[i][j] += dp[i - 1][j]
        dp[i][j] %= (10 ** 9 + 7)
print(dp[H][K - 1] % (10 ** 9 + 7))