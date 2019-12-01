N, M = map(int, input().split())
a_list = [int(input()) for _ in range(M)]

mod = 10 ** 9 + 7

dp = [0] * (N + 100)
dp[0] = 1
a_set = set(a_list)

for i in range(N):
    if i in a_set:
        continue
    else:
        dp[i + 1] += dp[i]
        dp[i + 1] %= mod
        dp[i + 2] += dp[i]
        dp[i + 2] %= mod

print(dp[N] % mod)
