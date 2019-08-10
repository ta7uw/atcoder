N, M = map(int, input().split())
items = []
from collections import defaultdict
from heapq import *
di = defaultdict(list)
for i in range(N):
    a, b = map(int, input().split())
    di[a].append(b)



ans = 0
target = []
heapify(target)

for i in range(1, M+1):
    if i in di:
        tmp = di[i]
        for t in tmp:
            heappush(target, -t)


    if len(target) >0 :
        q = heappop(target)
        ans += -q
print(ans)


