S = input()
N = len(S)
dp = [[0] * 2 for _ in range(N + 1)]

if N == 1:
    print(1)
    exit()

if S[0] == S[1]:
    dp[0][0] = 0
    dp[1][1] = 1
    dp[0][1] = 1
    dp[1][0] = 1
else:
    dp[0][0] = 0
    dp[0][1] = 1
    dp[1][0] = 1
    dp[1][1] = 2

for i in range(2, N):
    if S[i - 1] != S[i]:
        dp[i][1] = dp[i - 1][1] + 1
        dp[i][0] = dp[i - 2][1] + 1
    else:
        dp[i][1] = dp[i - 1][0] + 1
        dp[i][0] = dp[i - 2][1] + 1
print(max(dp[N - 1][0], dp[N - 1][1]))
