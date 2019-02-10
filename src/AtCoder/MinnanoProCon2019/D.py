L = int(input())
a_list = [int(input()) for _ in range(L)]

dp = [[0] * 5 for _ in range(L + 1)]

for i in range(L):
    a = a_list[i]

    if a > 0:
        even = a % 2
    else:
        even = 2
    odd = (a + 1) % 2

    # 0
    dp[i + 1][0] = dp[i][0] + a
    # 0でない偶数
    dp[i + 1][1] = min(dp[i][0], dp[i][1]) + even
    # 奇数
    dp[i + 1][2] = min(dp[i][0], dp[i][1], dp[i][2]) + odd
    # 0でない偶数
    dp[i + 1][3] = min(dp[i][0], dp[i][1], dp[i][2], dp[i][3]) + even
    # 0
    dp[i + 1][4] = min(dp[i][0], dp[i][1], dp[i][2], dp[i][3], dp[i][4]) + a
print(min(dp[L]))
