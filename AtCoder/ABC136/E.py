N, K = map(int, input().split())
a_list = list(map(int, input().split()))


def divisors(num):
    """
    約数全列挙
    """
    divisors = []
    for i in range(1, int(num ** 0.5) + 1):
        if num % i == 0:
            divisors.append(i)
            if i != num // i:
                divisors.append(num // i)

    return divisors


sum_num = sum(a_list)
a_list.sort()
div = divisors(sum_num)
div.sort(reverse=True)
ans = 1
from itertools import accumulate

for d in div:
    mod = []
    if d == 1:
        break
    for a in a_list:
        mod.append(a % d)
    mod.sort()
    acc_m = list(accumulate(mod))
    modd = []
    for i in range(N):
        modd.append(d - mod[i])
    acc_p = list(accumulate(modd))
    flag = False
    for i in range(N - 1):
        p_sum = acc_p[-1] - acc_p[i]
        n_sum = acc_m[i]
        if p_sum == n_sum and p_sum <= K:
            flag = True
    if flag:
        ans = d
        break

print(ans)
