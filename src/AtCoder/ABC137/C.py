N = int(input())
s_list = [input() for _ in range(N)]
from collections import defaultdict
def combination(n, r):
    """
    :param n: the count of different items
    :param r: the number of select
    :return: combination
    n! / (r! * (n - r)!)
    """
    r = min(n - r, r)
    result = 1
    for i in range(n, n - r, -1):
        result *= i
    for i in range(1, r + 1):
        result //= i
    return result

di = defaultdict(int)
for S in s_list:

    tmp = defaultdict(int)
    for s in S:
        tmp[s] += 1
    T = ""
    tmp = sorted(tmp.items())
    for t, t2 in tmp:
        T += t+ str(t2)
    di[T] += 1
ans = 0
for k, v in di.items():
    if v > 1:
        ans += combination(v, 2)
print(ans)
