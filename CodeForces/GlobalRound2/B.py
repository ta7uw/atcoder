N, H = map(int, input().split())
a_list = list(map(int, input().split()))

ans = 0
if a_list[0] > H:
    print(0)
    exit()

import bisect

que = [a_list[0]]
ans = 1
prev = []
now_h = 0

for i, a in enumerate(a_list[1:]):
    i += 1
    bisect.insort_right(que, a)

    tmp = que.copy()
    tmp = list(reversed(tmp))
    now_h = 0
    k = 0
    f = False
    while True:
        first = tmp[k]
        if now_h + first > H:
            break
        else:
            k += 2
            now_h += first
            if k > len(tmp) - 1:
                f = True
                break
    if f:
        ans += 1
    else:
        break

print(ans)
