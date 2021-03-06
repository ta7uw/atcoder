def pow_mod(n, k, mod):
    """
    Exponentiation by squaring
    https://atcoder.jp/contests/atc002/tasks/atc002_b
    :return: n ** k
    """

    if k == 0:
        return 1

    elif k & 1 == 1:
        return pow_mod(n, k - 1, mod) * n % mod
    else:
        tmp = pow_mod(n, k // 2, mod)
        return tmp * tmp % mod
