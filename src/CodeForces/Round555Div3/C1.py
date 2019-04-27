N = int(input())
a_list = list(map(int, input().split()))
from collections import deque

deq = deque(a_list)
ans = ""
left = 0
right = 0
min_num = -1
cnt = 0
f = False
while len(deq) >= 2:
    left = deq.popleft()
    right = deq.pop()
    # print(left, right)
    max_num = max(left, right)
    if max_num > min_num:
        cnt += 1
        if right > left > min_num:
            ans += "L"
            deq.append(right)
            min_num = left
        elif left > right > min_num:
            ans += "R"
            deq.appendleft(left)
            min_num = right
        elif left > min_num:
            ans += "L"
            deq.append(right)
            min_num = left
        else:
            ans += "R"
            deq.appendleft(left)
            min_num = right
    else:
        f = True
        break
if f:
    print(cnt)
    print(ans)
else:
    tmp = deq.pop()
    if tmp > min_num:
        cnt += 1
        print(cnt)
        print(ans + "R")
    else:
        print(cnt)
        print(ans)
