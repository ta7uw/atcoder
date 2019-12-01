def prime_factorize(num):
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


from fractions import gcd

N, K = map(int, input().split())
a_list = list(map(int, input().split()))

prime_factor = prime_factorize(K)
gcd_map = {}
for a in a_list:
    g = gcd(K, a)
    if g in gcd_map.keys():
        gcd_map[g] += 1
    else:
        gcd_map[g] = 1

if K == 1:
    prime_factor[1] = 1
prime_factor = list(prime_factor.items())
prime_list = []
for div in divisorize(prime_factor):
    prime_list.append(num(div))

from itertools import combinations_with_replacement

ans = 0
if K == 1:
    prime_list = [1]
for c in combinations_with_replacement(prime_list, 2):
    c1 = c[0]
    c2 = c[1]
    if c1 in gcd_map and c2 in gcd_map:
        if c1 == c2 and (c1 * c2) % K == 0:
            ans += (gcd_map[c1] * (gcd_map[c1] - 1)) // 2
        elif (c1 * c2) % K == 0:
            ans += (gcd_map[c1] * gcd_map[c2])

print(ans)
