N = int(input())
a_list = []
b_list = []
c_list = []
a_append = a_list.append
b_append = b_list.append
c_append = c_list.append
for i in range(N):
    a, b, c = map(int, input().split())
    a_append(a)
    b_append(b)
    c_append(c)

dp = [[-1 for _ in range(3)] for _ in range(N + 1)]

for i in range(1, N + 1):

    if i == 1:
        dp[i][0] = a_list[i - 1]
        dp[i][1] = b_list[i - 1]
        dp[i][2] = c_list[i - 1]
    else:
        dp[i][0] = max(dp[i][0], dp[i - 1][1] + a_list[i - 1])
        dp[i][0] = max(dp[i][0], dp[i - 1][2] + a_list[i - 1])
        dp[i][1] = max(dp[i][1], dp[i - 1][0] + b_list[i - 1])
        dp[i][1] = max(dp[i][1], dp[i - 1][2] + b_list[i - 1])
        dp[i][2] = max(dp[i][2], dp[i - 1][0] + c_list[i - 1])
        dp[i][2] = max(dp[i][2], dp[i - 1][1] + c_list[i - 1])

print(max(dp[N]))