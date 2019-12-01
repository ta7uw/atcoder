N = int(input())
a_list = list(map(int, input().split()))
from heapq import *

que = []

for i, a in enumerate(a_list):
    que.append((-a, i + 1))

cnt = 0
ans = []
heapify(que)

while len(que) >= 1:
    q = heappop(que)
    cnt += len(ans) * -q[0] + 1
    ans.append(q[1])
print(cnt)
for a in ans:
    print(a, end=" ")
