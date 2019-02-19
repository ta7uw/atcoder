from itertools import accumulate

N, K = map(int, input().split())
a_list = list(map(int, input().split()))

mod = 10 ** 9 + 7

dp = [0] * (K + 1)
dp[0] = 1

for i in range(N):
    acc_dp = [0] + list(accumulate(dp))

    cand_dp = [0] * (K + 1)
    for k in range(K + 1):
        cand_dp[k] = acc_dp[k + 1] - acc_dp[max(0, k - a_list[i])]
        cand_dp[k] %= mod
    dp = cand_dp
print(dp[K])
