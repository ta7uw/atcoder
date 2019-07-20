import sys
from bisect import bisect_right, insort_left
from collections import deque

N = int(sys.stdin.readline())
a_list = [int(sys.stdin.readline()) for _ in range(N)]

que = []
que = deque(que)

ans = 0
min_num = float("inf")
for i, a in enumerate(a_list):
    if i == 0:
        que.append(a)
        min_num = a
        ans += 1
    else:
        idx = bisect_right(que, a - 1)

        if idx == 0:
            que.appendleft(a)
            ans += 1
            min_num = a
        else:
            idx = bisect_right(que, a - 1)
            que[idx - 1] = a
            if idx - 1 == 0:
                min_num = a
    # print(que, min_num)
print(ans)
