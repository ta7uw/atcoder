A, B, Q = map(int, input().split())
s_list = [int(input()) for i in range(A)]
t_list = [int(input()) for i in range(B)]
x_list = [int(input()) for _ in range(Q)]

s_list.sort()
t_list.sort()
s_list = [-float("inf")] + s_list + [float("inf")]
t_list = [-float("inf")] + t_list + [float("inf")]
import bisect

ans = []
for x in x_list:
    tmp = float("inf")
    s_i = bisect.bisect_left(s_list, x)
    t_i = bisect.bisect_left(t_list, x)

    for s in (s_list[s_i - 1], s_list[s_i]):
        for t in (t_list[t_i - 1], t_list[t_i]):
            d1 = abs(s - x) + abs(t - s)
            d2 = abs(t - x) + abs(s - t)
            tmp = min(tmp, d1, d2)
    ans.append(tmp)
for a in ans:
    print(a)
