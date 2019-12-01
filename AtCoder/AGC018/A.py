N, K = map(int, input().split())
a_list = list(map(int, input().split()))

a_list.sort()
max_num = a_list[-1]

if max_num < K:
    print("IMPOSSIBLE")
    exit()

exist = a_list.count(K)
if exist >= 1:
    print("POSSIBLE")
    exit()

from fractions import gcd
gcd_num = gcd(a_list[-1], a_list[-2])

for a in a_list:
    gcd_num= gcd(gcd_num, a)
if K%gcd_num == 0:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
