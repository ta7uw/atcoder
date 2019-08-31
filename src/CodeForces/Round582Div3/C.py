Q = int(input())
from itertools import accumulate

ans = []
for q in range(Q):
    n, m = map(int, input().split())

    target = []
    z = m
    for i in range(10):
        target.append(z % 10)
        z += m
    tar_acc = list(accumulate(target))
    tmp = n // (10 * m)
    X = sum(target) * tmp
    if (n - (m * 10) * tmp) // m >= 1:
        X += tar_acc[((n - (m * 10) * tmp) // m) - 1]
    ans.append(X)
for a in ans:
    print(a)
