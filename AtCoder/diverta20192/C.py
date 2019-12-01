N = int(input())
a_list = list(map(int, input().split()))
a_list.sort()

from collections import deque

deq = deque(a_list)
res = []
while len(deq) > 2:
    min_num = deq.popleft()
    max_num = deq.pop()
    if min_num < 0 and max_num > 0:
        ne = deq.pop()
        if ne >= 0:
            res.append((min_num, ne))
            min_num -= ne
            deq.appendleft(min_num)
            deq.append(max_num)
        else:
            res.append((max_num, ne))
            max_num -= ne
            deq.append(max_num)
            deq.appendleft(min_num)
    else:
        if max_num <= 0:
            res.append((max_num, min_num))
            max_num = max_num - min_num
            deq.append(max_num)
        else:
            res.append((min_num, max_num))
            min_num = min_num - max_num
            deq.appendleft(min_num)

tmp1 = deq[0]
tmp2 = deq[1]
res.append((max(tmp1, tmp2), min(tmp2, tmp1)))
ans = max(tmp1, tmp2) - min(tmp2, tmp1)
print(ans)
for x, y in res:
    print(x, y)
