N = int(input())
h_list = list(map(int, input().split()))

dp = [float("inf") for _ in range(N + 1)]
dp[1] = 0
for i in range(2, N + 1):
    if i == 2:
        dp[2] = abs(h_list[1] - h_list[0])
    else:
        dp[i] = min(dp[i - 1] + abs(h_list[i-1] - h_list[i - 2]), dp[i - 2] + abs(h_list[i-1] - h_list[i - 3]))
print(dp[N])