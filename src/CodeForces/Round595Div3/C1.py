"""
C1. Good Numbers (easy version)
https://codeforces.com/contest/1249/problem/C1

答えの候補を全列挙して二分探索して N 以上の最小の値を探す。
制約的に二分探索しなくてもたぶんまにあう

"""

tar = []

for i in range(10):
    tmp = 3 ** i
    tar.append(tmp)
    tmp2 = tar.copy()
    for t in tmp2:
        if t != tmp:
            tar.append(t + tmp)


from bisect import *

Q = int(input())
for q in range(Q):
    N = int(input())
    idx = bisect_left(tar, N)
    print(tar[idx])
