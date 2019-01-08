N = int(input())
a_list = list(map(int, input().split()))

from collections import Counter

a_set = set(a_list)
counter = Counter(a_list)

remove = 0
for k, v in counter.items():
    if v > 1:
        remove += v - 1

if remove % 2 == 0:
    print(len(a_set))
else:
    print(len(a_set) - 1)
