N = int(input())


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


import math

fac = math.factorial(N)
prime_fac = prime_factorize(fac)

count = 0
upper_two = {}
upper_four = {}
upper_15 = {}
upper_24 = {}
upper_74 = {}


for k, v in prime_fac.items():
    if v >= 2:
        upper_two[k] = v
    if v >= 4:
        upper_four[k] = v
    if v >= 14:
        upper_15[k] = v
    if v >= 24:
        upper_24[k] = v
    if v >= 74:
        upper_74[k] = v


upper_two = len(upper_two)
upper_four = len(upper_four)
upper_15 = len(upper_15)
upper_24 = len(upper_24)
upper_74 = len(upper_74)


ans = upper_four*(upper_four - 1) * (upper_two-2)//2 \
      + upper_74 + upper_24 * (upper_two-1) + upper_15 * (upper_four-1)


print(ans)