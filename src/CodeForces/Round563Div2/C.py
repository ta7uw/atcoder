N = int(input())


def prime_list(num):
    """
    This function returns a list of prime numbers less than natural number entered.
    :param num: natural number
    :return result:  List of primes less than natural number entered
    """
    prime_table = [True for _ in range(num + 1)]
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


ans = []
prime = prime_list(N + 1)


def check(num, dic):
    for p in prime:
        if num % p == 0:
            return dic[p]


p_set = set(prime)
r_prime = list(reversed(prime))
inc = 2
res = dict()
for i in range(2, N + 1):
    if i % 2 == 0:
        ans.append(1)
    else:
        if i in p_set:
            ans.append(inc)
            res[i] = inc
            inc += 1
        else:
            ans.append(check(i, res))
for a in ans:
    print(a, end=" ")
print()
