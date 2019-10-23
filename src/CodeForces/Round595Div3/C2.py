"""
C2. Good Numbers (hard version)
https://codeforces.com/contest/1249/problem/C2

3^i (0 <= i < 40 ) の値を求め、それらの和を求める。
この和から上の要素を大きい順に N より小さくならないように引いていく
3^(i+1) が 3^iまでの和より大きいことによりこの貪欲法が使える

"""

tar = []

for i in range(40):
    tmp = 3 ** i
    tar.append(tmp)


# print(str(max(tar)))
# print(len(str(max(tar))))
sum_num = sum(tar)
tar = list(reversed(tar))
from bisect import *
Q = int(input())
for q in range(Q):
    N = int(input())
    tar2 = tar.copy()
    ans = sum_num
    idx = -1
    for i, t in enumerate(tar2):
        if ans - t >= N:
            ans -= t
            continue
    print(ans)
