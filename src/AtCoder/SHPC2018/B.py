N, K = map(int, input().split())
b_list = [int(input()) for _ in range(N)]

dp = [0] * (N + 1)
tmp = 0
for i, b in enumerate(b_list):
    if i < K - 1:
        dp[i + 1] += dp[i] + b
    else:
        tmp = max(tmp, dp[i - K + 1])
        dp[i+1] = max(dp[i] + b, tmp)
print(dp[N])
