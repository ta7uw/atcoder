n, p = map(int, input().split())

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


prime_fac = prime_factorize(p)
counts = []
for k, v in prime_fac.items():
    if v >= n:
        counts.append(k**(v//n))

counts.sort(reverse=True)
#print(prime_fac)
#print(counts)
if len(counts) == 0:
    print(1)
elif n == 1:
    print(p)
else:
    r = 1
    num = 0
    for c in counts:
        if num >= n:
            break
        r *= c
        num += 1
    print(r)