T = input()
N = len(T)
dp = [[0] * 2 for _ in range(N + 1)]
for i in range(N):
    t = T[i]
    if t == '2' or t == '?':
        dp[i + 1][0] = dp[i][1] + 1
    if (t == '5' or t == '?') and dp[i][0] > 0:
        dp[i + 1][1] = dp[i][0]

ans = 0
for i in range(N + 1):
    ans = max(ans, dp[i][1])
print(ans * 2)
