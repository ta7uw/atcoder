K = int(input())
N = 1 << K
r_list = [int(input()) for _ in range(N)]


def get_win_per(p, q):
    return 1 / (1 + 10 ** ((q - p) / 400))


def mask(k):
    return ((1 << (K - k)) - 1) << k


dp = [[0 for _ in range(K + 1)] for _ in range(N)]
for n in range(N):
    dp[n][0] = 1

for k in range(K):
    for n in range(N):
        l, d = (n & mask(k)) ^ (1 << k), 1 << k
        dp[n][k + 1] = dp[n][k] * sum(dp[m][k] * get_win_per(r_list[n], r_list[m]) for m in range(l, l + d))

for n in range(N):
    print("{0:.10f}".format(dp[n][K]))
