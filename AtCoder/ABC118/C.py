N = int(input())
a_list = list(map(int, input().split()))

import fractions

num = a_list[0]

for i in range(N):
    a = a_list[i]
    num = fractions.gcd(num, a)
print(num)
