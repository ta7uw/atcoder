N, K = map(int, input().split())
a_list = list(map(int, input().split()))

point = [[0] * 2 for _ in range(40)]

for i in range(40):
    tmp = 0
    for a in a_list:
        if (a >> (39 - i)) & 1:
            tmp += 1
    # 上位からiビット目が 0 のときに得られる値
    point[i][0] = tmp * 2 ** (39 - i)
    # 上位からiビット目が 1 のときに得られる値
    point[i][1] = (N - tmp) * 2 ** (39 - i)

dp = [[-float("inf")] * 2 for _ in range(41)]
dp[0][0] = 0

# 上位ビットから決めていったときの暫定値
# dpの2つ目の添字は0のときKに忠実に合わせていく。
# 1のときはKより小さいことがわかっている
for i in range(40):
    x = (K >> (39 - i)) & 1

    # 忠実にKに合わせていく
    dp[i + 1][0] = dp[i][0] + point[i][x]

    # すでにKよりも小さいことがわかっているのでずっとこの遷移をとる
    # 0と１のどちらを選んでも良い
    dp[i + 1][1] = dp[i][1] + max(point[i][0], point[i][1])

    # K の上位iビット目が1のときKに忠実な遷移から小さい遷移(0を選ぶ)に移れる。
    # それが最適とは限らない
    if x == 1:
        dp[i + 1][1] = max(dp[i][0] + point[i][0], dp[i + 1][1])
print(max(dp[40]))
