N = int(input())

mod = 10 ** 9 + 7

dp = [[[[0] * 4 for _ in range(4)] for _ in range(4)] for _ in range(N + 1)]

dp[0][3][3][3] = 1

for i in range(N):
    for j in range(4):
        for k in range(4):
            for m in range(4):
                if dp[i][j][k][m] == 0:
                    continue
                for l in range(4):
                    if l == 2 and j == 1 and k == 0:
                        continue
                    if l == 2 and j == 0 and k == 1:
                        continue
                    if l == 1 and j == 2 and k == 0:
                        continue
                    if l == 2 and j == 1 and m == 0:
                        continue
                    if l == 2 and k == 1 and m == 0:
                        continue
                    dp[i + 1][l][j][k] += dp[i][j][k][m]
                    dp[i + 1][l][j][k] %= mod

ans = 0
for i in range(4):
    for j in range(4):
        for k in range(4):
            ans += dp[N][i][j][k]
            ans %= mod
print(ans)
