n, m = map(int, input().split())
a_list = list(map(int, input().split()))

sum_list = [0 for _ in range(n)]
sum_list[0] = a_list[0]
for i in range(n - 1):
    sum_list[i + 1] += sum_list[i] + a_list[i + 1]

c_list = [0]
for s in sum_list:
    c_list.append(s % m)
from collections import Counter

counter = Counter(c_list)
count = 0

for k, v in counter.items():
    if v >= 2:
        count += v * (v - 1) // 2

print(count)