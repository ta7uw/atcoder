N, M, P = map(int, input().split())


def pow_mod(n, k, mod):
    """
    Exponentiation by squaring
    :return: n ** k
    """
    r = 1
    while k > 0:
        if k & 1:
            r = r * n % mod
        n = n * n % mod
        k >>= 1
    return r


print(pow_mod(N, P, M))