N, T = map(int, input().split())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))

min_i = float("inf")
min_s = float("inf")
f = False
min_t = float("inf")
min_j = float("inf")
import math

for i, item in enumerate(items):
    s, t = item
    if T <= s < min_s:
        min_s = s
        min_i = i + 1
    if s < T:
        tmp = s
        div = math.ceil((T - s) / t)
        tmp += div * t
        if T <= tmp < min_t:
            min_t = tmp
            min_j = i + 1

if min_s <= min_t:
    print(min_i)
else:
    print(min_j)
