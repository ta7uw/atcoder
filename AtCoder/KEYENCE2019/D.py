N, M = map(int, input().split())
a_list = tuple(map(int, input().split()))
b_list = tuple(map(int, input().split()))
mod = 10 ** 9 + 7

# 同じもの含んでいたらアウト
a_set = set(a_list)
b_set = set(b_list)
if len(a_set) < N or len(b_set) < M:
    print(0)
    exit()

# 大きいものから順にみていく
a_list = sorted(a_list, reverse=True)
b_list = sorted(b_list, reverse=True)

# １つ余分につけておく
a_list.append(-1)
b_list.append(-1)
ans = 1
a_i = 0
b_i = 0
for i in range(N*M, 0, -1):
    if i == a_list[a_i] and i == b_list[b_i]:
        # iが両方に出現
        a_i += 1
        b_i += 1
    elif i == a_list[a_i]:
        # iがAのみに出現
        a_i += 1
        ans *= b_i
        ans %= mod
    elif i == b_list[b_i]:
        # iがBのみに出現
        b_i += 1
        ans *= a_i
        ans %= mod
    else:
        # iがA, Bどちらにも出現しない、置き場がないときans = 0になる
        ans *= (a_i*b_i - (N * M - i))
        ans %= mod
print(ans % mod)

