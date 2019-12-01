N = int(input())
p_list = list(map(float, input().split()))

dp = [[0.0 for _ in range(N + 1)] for _ in range(N + 1)]
dp[1][1] = p_list[0]
dp[1][0] = 1 - p_list[0]

for i in range(2, N + 1):
    for j in range(i + 1):
        dp[i][j] = p_list[i - 1] * dp[i - 1][j - 1] + (1 - p_list[i - 1]) * dp[i - 1][j]

print("{:.10f}".format(sum(dp[N][N // 2 + 1:])))
