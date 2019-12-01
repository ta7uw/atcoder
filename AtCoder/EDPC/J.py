N = int(input())
a_list = list(map(int, input().split()))

one, two, three = 0, 0, 0
for a in a_list:
    if a == 1:
        one += 1
    if a == 2:
        two += 1
    if a == 3:
        three += 1

dp = [[[0.0] * 301 for _ in range(301)] for _ in range(301)]
for k in range(three + 1):
    for j in range(two + three + 1 - k):
        for i in range(one + two + three + 1 - k - j):
            if i == 0 and j == 0 and k == 0:
                continue
            tmp = N * 1.0
            if i != 0:
                tmp += i * dp[i - 1][j][k]
            if j != 0:
                tmp += j * dp[i + 1][j - 1][k]
            if k != 0:
                tmp += k * dp[i][j + 1][k - 1]

            dp[i][j][k] = tmp / (i + j + k)
print(dp[one][two][three])
