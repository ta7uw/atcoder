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


def divisorize(fct):
    b, e = fct.pop()  # base, exponent
    pre_div = divisorize(fct) if fct else [[]]
    suf_div = [[(b, k)] for k in range(e + 1)]
    return [pre + suf for pre in pre_div for suf in suf_div]


def num(fct):
    a = 1
    for base, exponent in fct:
        a = a * base ** exponent
    return a


N, M = map(int, input().split())
x_list = list(map(int, input().split()))
p_list = list(map(int, input().split()))

y = x_list[0]

import math

nums = x_list[0] - y
for p in x_list[1:]:
    p = p - y
    nums = math.gcd(nums, p)

if nums != 1:
    prime_factor = prime_factorize(nums)
    prime_factor = list(prime_factor.items())
    prime_list = []
    for div in divisorize(prime_factor):
        prime_list.append(num(div))
else:
    prime_list = [1]
for pr in prime_list:
    for i in range(M):
        if p_list[i] == pr:
            print("YES")
            print(y, i + 1)
            exit()
print("NO")
