l, r = map(int, input().split())
mod = 10 ** 9 + 7


def f(x):
    if x == 0:
        return 0
    res = 1
    cnt = 2
    f = 1
    b_s = 2
    e_s = 4
    b_f = 3
    e_f = 9
    x -= 1
    while x > 0:
        if f:
            res += cnt * (b_s + e_s) // 2
            b_s = e_s + 2
            e_s = e_s + 2 * (4 * cnt)
        else:
            res += cnt * (b_f + e_f) // 2
            b_f = e_f + 2
            e_f = e_f + 2 * (4 * cnt)
        x -= cnt
        if x < 0:
            if f:
                b_s -= 2
                res -= abs(x) * (b_s + b_s - abs(x + 1) * 2) // 2
            else:
                b_f -= 2
                res -= abs(x) * (b_f + b_f - abs(x + 1) * 2) // 2
        cnt *= 2
        f = 1 - f
    return res


print((f(r) - f(l - 1)) % mod)
