Q = int(input())
from heapq import *

for q in range(Q):
    n = int(input())
    a_list = list(map(int, input().split()))

    b_list = []
    found = False
    for a in a_list:
        if a == 2048:
            found = True
            break
        elif a <= 1024:
            b_list.append(a)

    if found:
        print("Yes")
        continue

    heapify(b_list)
    while len(b_list) >= 2:
        b1 = heappop(b_list)
        b2 = heappop(b_list)
        if b1 == 1024 and b2 == 1024:
            found = True
            break
        if b1 == b2:
            heappush(b_list, b1 + b2)
        else:
            if b1 > b2:
                heappush(b_list, b1)
            else:
                heappush(b_list, b2)
    if found:
        print("Yes")
    else:
        print("No")
