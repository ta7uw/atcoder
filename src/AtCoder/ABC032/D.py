import bisect

N, W = map(int, input().split())
items = []
v_max = 0
w_max = 0
for i in range(N):
    v, w = map(int, input().split())
    if v > v_max:
        v_max = v
    if w > w_max:
        w_max = w
    items.append((v, w))


def knapsack1():
    v_list = []
    w_list = []
    for item in items:
        v, w = item
        v_list.append(v)
        w_list.append(w)

    a_list = []
    for i in range(2 ** (N // 2)):
        bit = bin(2 ** (N // 2) + i)[3:]
        sw = sum([d for d, s in zip(w_list, bit) if s == "1"])
        sv = sum([d for d, s in zip(v_list, bit) if s == "1"])
        a_list.append([sw, sv])
    a_list.sort()

    b_list = []
    for i in range(2 ** (N - N // 2)):
        bit = bin(2 ** (N - N // 2) + i)[3:]
        sw = sum([d for d, s in zip(w_list[N // 2:], bit) if s == "1"])
        sv = sum([d for d, s in zip(v_list[N // 2:], bit) if s == "1"])
        b_list.append([sw, sv])
    b_list.sort()

    z_list = [0]
    for w, v in b_list:
        z_list.append(max(z_list[-1], v))

    ans = 0
    for w, v in a_list:
        if w > W:
            continue

        i = bisect.bisect_right(b_list, [W - w, float('inf')])
        ans = max(ans, v + z_list[i])
    print(ans)


def knapsack2():
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


def knapsack3():
    dp = [[0 for _ in range(W + 1)] for _ in range(N + 1)]
    for i in range(N):
        for j in range(W + 1):
            if j - items[i][1] >= 0:
                dp[i + 1][j] = max(dp[i][j], dp[i][j - items[i][1]] + items[i][0])
            else:
                dp[i + 1][j] = dp[i][j]
    print(dp[N][W])


if w_max <= 1000:
    knapsack3()
elif v_max <= 1000:
    knapsack2()
else:
    knapsack1()
