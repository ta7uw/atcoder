N, Ma, Mb = map(int, input().split())
items = []
for i in range(N):
    a, b, c = map(int, input().split())
    items.append((a, b, c))

a_sum = sum([item[0] for item in items])
b_sum = sum([item[1] for item in items])
inf = float("inf")
dp = [[[inf for _ in range(b_sum + 11)] for _ in range(a_sum + 11)] for i in range(N + 1)]
dp[0][0][0] = 0
for i in range(N):
    for a in range(a_sum):
        for b in range(b_sum):
            if dp[i + 1][a][b] > dp[i][a][b]:
                dp[i + 1][a][b] = dp[i][a][b]
            if dp[i + 1][a + items[i][0]][b + items[i][1]] > dp[i][a][b] + items[i][2]:
                dp[i + 1][a + items[i][0]][b + items[i][1]] = dp[i][a][b] + items[i][2]

ans = inf
for a in range(1, a_sum + 1):
    for b in range(1, b_sum + 1):
        if a * Mb == b * Ma:
            ans = min(ans, dp[N][a][b])
if ans != inf:
    print(ans)
else:
    print(-1)
