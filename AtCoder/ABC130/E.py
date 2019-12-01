N, M = map(int, input().split())
s_list = list(map(int, input().split()))
t_list = list(map(int, input().split()))

mod = 10 ** 9 + 7


def solve(x, y):
    dp = [[0 for _ in range(M + 1)] for _ in range(N + 1)]
    for i in range(1, N + 1):
        for j in range(1, M + 1):
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]
            dp[i][j] %= mod
            if x[i - 1] == y[j - 1]:
                dp[i][j] += dp[i - 1][j - 1] + 1
                dp[i][j] %= mod
    return dp


ans = solve(s_list, t_list)
print((ans[N][M] + 1) % mod)
