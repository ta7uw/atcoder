S = input()
N = len(S)
mod = 10 ** 9 + 7
dp = [[0] * 13 for _ in range(N + 1)]

dp[0][0] = 1
for i in range(N):
    s = S[i]
    if s == "?":
        for j in range(10):
            for k in range(13):
                dp[i + 1][(10 * k + j) % 13] += dp[i][k]
                dp[i + 1][(10 * k + j) % 13] %= mod
    else:
        j = int(s)
        for k in range(13):
            dp[i + 1][(10 * k + j) % 13] += dp[i][k]
            dp[i + 1][(10 * k + j) % 13] %= mod

print(dp[N][5] % mod)
