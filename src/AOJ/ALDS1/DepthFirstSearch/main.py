n = int(input())
graph = [[] for _ in range(n)]
for i in range(n):
    in_list = list(map(int, input().split()))
    u = in_list[0]
    graph[u - 1] = in_list[2:]

d = [0 for _ in range(n)]
f = [0 for _ in range(n)]
time = 0

def dfs(now, prev, graph, d, f, time):
    if d[now] != 0:
        return d, f, time
    time += 1
    d[now] = time
    if not graph[now]:
        f[now] = time + 1
        time += 1
        return d, f, time
    for k in graph[now]:
        if k - 1 == prev or d[k-1] !=0:
            continue
        _, _, time = dfs(k - 1, now, graph, d, f, time)
    else:
        time += 1
        f[now] = time
    return d, f, time



for i in range(n):
    d, f, time = dfs(i, 0, graph, d, f, time)
    print(i+1, d[i], f[i])
