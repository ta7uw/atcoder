n, m = map(int, input().split())
c_list = list(map(int, input().split()))


def get_coin_number(coin_list, n, m):
    t = [float("inf") for i in range(n + 1)]
    t[0] = 0

    for i in range(1, m + 1):
        for j in range(coin_list[i-1], n + 1):
            t[j] = min(t[j], t[j - coin_list[i-1]] + 1)
    return t[n]


print(get_coin_number(c_list, n, m))
