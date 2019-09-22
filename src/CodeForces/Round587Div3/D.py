N = int(input())
a_list = list(map(int, input().split()))
from math import gcd

max_a = max(a_list)

margin = []

for a in a_list:
    if a != max_a:
        margin.append(max_a - a)

a = 0

for i in range(len(margin)):
    a = gcd(a, margin[i])

sum_margin = sum(margin)
print(sum_margin // a, a)
