N = int(input())
a_list = list(map(int, input().split()))
import math
def combinations_count(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

s = []
s.append(0)

for i, a in enumerate(a_list):
    tmp = a + s[i]
    s.append(tmp)

s.sort()

s_dict = {}
for si in s:
    if si in s_dict.keys():
        s_dict[si] += 1
    else:
        s_dict[si] = 1
count = 0
for c in s_dict.values():
    if c >= 2:
        count += combinations_count(c, 2)
print(count)


