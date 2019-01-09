N, K = map(int, input().split())
h_list = list(map(int, input().split()))

inf = float("inf")
dp = [inf for _ in range(N + 1)]
dp[1] = 0
for i in range(1, N + 1):
    for k in range(1, K + 1):
        if i + k <= N:
            if dp[i + k] > dp[i] + abs(h_list[i - 1] - h_list[i - 1 + k]):
                dp[i + k] = dp[i] + abs(h_list[i - 1] - h_list[i - 1 + k])

print(dp[N])