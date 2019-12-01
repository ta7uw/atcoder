from itertools import accumulate

N = int(input())
a_list = list(map(int, input().split()))

a_acc = [0] + list(accumulate(a_list))

dp = [[0] * (N + 1) for _ in range(N + 1)]

for d in range(2, N + 1):
    for l in range(N + 1 - d):
        r = l + d
        tmp = float("inf")
        for m in range(l + 1, r):
            tmp = min(tmp, dp[l][m] + dp[m][r])
        dp[l][r] = tmp + a_acc[r] - a_acc[l]

print(dp[0][N])
