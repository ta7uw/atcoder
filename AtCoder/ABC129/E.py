L = input()
N = len(L)
mod = 10 ** 9 + 7
dp = [[0] * 2 for _ in range(N + 10)]

dp[0][0] = 1
for i in range(1, N + 1):
    s = L[i - 1]
    if s == "1":
        dp[i][0] += 2 * dp[i - 1][0] % mod
        dp[i][1] += dp[i - 1][0] % mod
    else:
        dp[i][0] += dp[i - 1][0] % mod

    dp[i][1] += dp[i - 1][1] * 3 % mod

print((dp[N][0] + dp[N][1]) % mod)
