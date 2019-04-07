from collections import defaultdict
import string


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


alphabet = string.ascii_uppercase

T = int(input())

for t in range(T):
    n, l = map(int, input().split())
    text = tuple(map(int, input().split()))

    i = 0
    while text[i] == text[i + 1]:
        i += 1
    g = gcd(text[i], text[i + 1])
    primes = [0] * (l + 1)
    primes[i + 1] = g
    for j in range(i + 1, l):
        primes[j + 1] = text[j] // primes[j]
    for j in range(i, -1, -1):
        primes[j] = text[j] // primes[j + 1]

    use_prime_set = list(set(primes))
    use_prime_set = sorted(use_prime_set)
    alphabet_map = defaultdict()

    for x in range(len(use_prime_set)):
        alphabet_map[use_prime_set[x]] = alphabet[x]
    tmp = ""
    for p in primes:
        tmp += alphabet_map[p]

    t += 1
    print("Case #{}: {}".format(t, tmp))
