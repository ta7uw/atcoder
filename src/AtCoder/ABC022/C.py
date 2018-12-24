N, M = map(int, input().split())
input_route = [[float("inf") for _ in range(N)] for _ in range(N)]

next_points = []

for i in range(M):
    u, v, l = map(int, input().split())
    if u == 1:
        next_points.append([v-1, l])
        continue
    if v == 1:
        next_points.append([u-1, l])
        continue
    input_route[u - 1][v - 1] = l
    input_route[v - 1][u - 1] = l

for i in range(N):
    input_route[i][i] = 0

# def warshall_floyd(n, route):
#
#     for k in range(n):
#         for i in range(n):
#             for j in range(n):
#                 route[i][j] = min(route[i][j], route[i][k] + route[k][j])
#     return route

from scipy.sparse.csgraph import floyd_warshall
route = floyd_warshall(input_route, directed=False)

from itertools import combinations
chokudai_route = list(combinations(next_points, 2))
result = float("inf")
for start_choku, goal_choku in chokudai_route:
    cost = start_choku[1] + goal_choku[1]
    result = min(result, route[start_choku[0]][goal_choku[0]] + start_choku[1] + goal_choku[1])



if result == float("inf"):
    print(-1)
else:
    print(int(result))