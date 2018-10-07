def prime_list(num):
    """
    This function returns a list of prime numbers less than natural number entered.
    :param num: natural number
    :return result:  List of primes less than natural number entered
    """
    prime_table = [True for _ in range(num+1)]
    i = 2
    while i ** 2 <= num:
        if prime_table[i]:
            j = i + i
            while j <= num:
                prime_table[j] = False
                j += i
        i += 1

    result = [i for i in range(num) if prime_table[i] and i >= 2]
    return result
