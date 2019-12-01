N, Q = map(int, input().split())
S = input()
items = []
for i in range(Q):
    items.append(tuple(map(int, input().split())))

from itertools import accumulate

prev = ""
acc = [0] * N
for i, s in enumerate(S):
    if s == "C" and prev == "A":
        acc[i] = 1
    prev = s

acc = list(accumulate(acc))
ans = []
for i in range(Q):
    l, r = items[i]

    ans.append(acc[r - 1] - acc[l - 1])
for a in ans:
    print(a)
