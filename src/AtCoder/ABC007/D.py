A, B = map(int, input().split())
A = A - 1
A = str(A)
B = str(B)


def f(num):
    length = len(num)
    dp = [[[0] * 2 for _ in range(2)] for _ in range(length + 1)]
    dp[0][0][0] = 1
    for i in range(length):
        for j in range(2):
            for k in range(2):
                if j == 1:
                    x = 9
                else:
                    x = int(num[i])
                for d in range(x + 1):
                    dp[i + 1][j or d < x][k or d == 4 or d == 9] += dp[i][j][k]
    ans = 0
    for i in range(2):
        ans += dp[length][i][1]
    return ans


print(f(B) - f(A))
