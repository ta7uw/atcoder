A, B = map(int, input().split())
a_list = list(map(int, input().split()))
b_list = list(map(int, input().split()))

dp = [[0 for _ in range(B + 1)] for _ in range(A + 1)]
dp[0][0] = 0

for i in range(A + 1):
    for j in range(B + 1):
        if (A + B - i - j) & 1 == 0:
            if i != 0 and j != 0:
                dp[i][j] = max(dp[i - 1][j] + a_list[A - i], dp[i][j - 1] + b_list[B - j])
            elif i != 0:
                dp[i][0] = dp[i - 1][0] + a_list[A - i]
            elif j != 0:
                dp[0][j] = dp[0][j - 1] + b_list[B - j]

        else:
            if i != 0 and j != 0:
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1])
            elif i != 0:
                dp[i][0] = dp[i - 1][0]
            elif j != 0:
                dp[0][j] = dp[0][j - 1]
print(dp[A][B])
