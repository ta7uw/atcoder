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
            num /= i
            if i in prime_factor.keys():
                prime_factor[i] += 1
            else:
                prime_factor[i] = 1
        i += 1
    if num > 1:
        prime_factor[num] += 1
    return prime_factor