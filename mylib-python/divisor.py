def divisor(num):
    """
    This function returns a list of divisors of natural numbers entered.
    :param num:
    :return: divisors: List of divisors of entered natural numbers
    """
    prime_factor = _prime_factorize(num)
    divisors = []
    divisors_list = _exec_combination(prime_factor)
    for div in divisors_list:
        result = 1
        for number, count in div:
            result = result * number ** count
        divisors.append(result)
    return divisors


def _prime_factorize(num):

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


def _exec_combination(prime_factorized_dic: dict):
    num, count = prime_factorized_dic.popitem()
    pre_div = _exec_combination(prime_factorized_dic) if prime_factorized_dic else [[]]
    suf_div = [[(num, k)] for k in range(count + 1)]
    return [pre + suf for pre in pre_div for suf in suf_div]
