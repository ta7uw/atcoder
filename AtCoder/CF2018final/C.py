import bisect

N = int(input())
ab = []
for i in range(N):
    ab.append(tuple(map(int, input().split())))

M = int(input())
t_list = [int(input()) for _ in range(M)]

a_list = []

cost = {}
for a, b in ab:
    a_list.append(a)
    cost[a] = b
a_list.sort()
for t in t_list:
    index = bisect.bisect_left(a_list, t)
    if index == N:
        index -= 1
    if t >= a_list[index]:
        c1 = cost[a_list[index]] + t - a_list[index]
    else:
        c1 = cost[a_list[index]]
    if t >= a_list[index - 1]:
        c2 = cost[a_list[index - 1]] + t - a_list[index - 1]
    else:
        c2 = cost[a_list[index - 1]]
    print(min(c1, c2))
