from collections import defaultdict, deque

N, M = map(int, input().split())

graph = defaultdict(list)

for i in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

ans = list(range(N + 1))
q = deque([1])
parents = [-1] * (N + 1)
parents[1] = 0
while len(q) > 0:
    v = q.pop()
    if ans[v] == v:
        f = True
    else:
        f = False

    for u in graph[v]:
        if parents[u] == -1:
            q.append(u)
            parents[u] = v
            if f:
                ans[u], ans[v] = ans[v], ans[u]
                f = False
    if f:
        ans[v], ans[parents[v]] = ans[parents[v]], ans[v]

print(*ans[1:])
