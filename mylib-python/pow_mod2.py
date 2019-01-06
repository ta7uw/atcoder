def pow_mod2(n, k, mod):
    """
    Exponentiation by squaring
    https://atcoder.jp/contests/atc002/tasks/atc002_b
    :return: n ** k
    """
    r = 1
    while k > 0:
        if k & 1:
            r = r * n % mod
        n = n * n % mod
        k >>= 1
    return r