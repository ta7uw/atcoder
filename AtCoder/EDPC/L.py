N = int(input())
a_list = list(map(int, input().split()))

dp = [[0] * (N + 1) for _ in range(N + 1)]

for i in range(1, N + 1):
    for l in range(N + 1 - i):
        r = l + i
        dp[l][r] = max(a_list[l] - dp[l + 1][r], a_list[r - 1] - dp[l][r - 1])

print(dp[0][N])
