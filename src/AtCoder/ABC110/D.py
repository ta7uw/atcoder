def prime_factorize(num):
    """
    This function performs prime factorization on the input natural number.
    The result is returned in the form of a dictionary with the prime number as the key
    and its number as the value.
    :param num:
    :return prime_factor: Dictionary with the prime number as the key and its number as the value.
    """
    prime_factor = {}
    i = 2
    while i ** 2 <= num:
        while num % i == 0:
            num //= i
            if i in prime_factor.keys():
                prime_factor[i] += 1
            else:
                prime_factor[i] = 1
        i += 1
    if num > 1:
        prime_factor[num] = 1
    return prime_factor


from math import factorial


def comb(n, r, R):
    if n not in R:
        a = factorial(n)
        R[n] = a
    else:
        a = R[n]

    if n - r not in R:
        b = factorial(n - r)
        R[n - r] = b
    else:
        b = R[n - r]

    if r not in R:
        c = factorial(r)
        R[r] = c
    else:
        c = R[r]
    return a // (b * c)


n, m = map(int, input().split())
r = 1

R = dict()
prime_fac = prime_factorize(m)
for v in prime_fac.values():
    r *= comb(v + n - 1, v, R)
mod = 1000000000 + 7
print(r % mod)
