from collections import Counter

N, C = map(int, input().split())
d_grid = []
for i in range(C):
    d_grid.append(tuple(map(int, input().split())))
c_list = []
for i in range(N):
    c_list.append(tuple(map(int, input().split())))

m0 = []
m1 = []
m2 = []
for i in range(N):
    for j in range(N):
        m = i + j + 2
        tmp = c_list[i][j]
        if m % 3 == 0:
            m0.append(tmp)
        if m % 3 == 1:
            m1.append(tmp)
        if m % 3 == 2:
            m2.append(tmp)

m0_count = Counter(m0)
m1_count = Counter(m1)
m2_count = Counter(m2)

ans = float("inf")

m0_cost = [0 for _ in range(C)]
m1_cost = [0 for _ in range(C)]
m2_cost = [0 for _ in range(C)]

for c1 in range(C):
    for c2 in range(C):
        cost = d_grid[c1][c2]
        m0_cost[c2] += m0_count[c1 + 1] * cost
        m1_cost[c2] += m1_count[c1 + 1] * cost
        m2_cost[c2] += m2_count[c1 + 1] * cost
for i in range(C):
    for j in range(C):
        for k in range(C):
            if i == j or i == k or j == k:
                continue
            ans = min(ans, m0_cost[i] + m1_cost[j] + m2_cost[k])
print(ans)
