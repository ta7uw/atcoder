N, W = map(int, input().split())
items = []

for i in range(N):
    v, w = map(int, input().split())


def knapsack1():
    v_sum = sum([item[0] for item in items])
    inf = float("inf")
    dp = [inf for _ in range(v_sum + 1)]
    dp[0] = 0
    for i in range(N):
        for j in range(v_sum, -1, -1):
            if dp[j] > dp[j - items[i][0]] + items[i][1]:
                dp[j] = dp[j - items[i][0]] + items[i][1]
    for i in range(v_sum, -1, -1):
        if dp[i] <= W:
            print(i)
            exit()


def knapsack2():
    dp = [[0 for _ in range(W + 1)] for _ in range(N + 1)]
    for i in range(N):
        for j in range(W + 1):
            if j - items[i][1] >= 0:
                dp[i + 1][j] = max(dp[i][j], dp[i][j - items[i][1]] + items[i][0])
            else:
                dp[i + 1][j] = dp[i][j]
    print(dp[N][W])
