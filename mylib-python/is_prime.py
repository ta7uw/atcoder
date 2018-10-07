def is_prime(num):
    """
    This function checks whether the input natural number larger than 1 is a prime number.
    :param num:
    :return: boolean
    """
    i = 2
    while i ** 2 <= num:
        if num % i == 0:
            return False
        i += 1
    return True