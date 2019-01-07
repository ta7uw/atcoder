N, W = map(int, input().split())

items = [list(map(int, input().split())) for _ in range(N)]
v_sum = sum([item[1] for item in items])

inf = float("inf")
dp = [inf for _ in range(v_sum + 1)]

dp[0] = 0
for i in range(N):
    for j in range(v_sum, -1, -1):
        if dp[j] > dp[j - items[i][1]] + items[i][0]:
            dp[j] = dp[j - items[i][1]] + items[i][0]

for i in range(v_sum, -1, -1):
    if dp[i] <= W:
        print(i)
        exit()
