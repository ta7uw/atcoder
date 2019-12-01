from collections import Counter

N, M = map(int, input().split())
graph = [[] for _ in range(N)]
for i in range(M):
    a, b, l = map(int, input().split())
    graph[a - 1].append(l)
    graph[b - 1].append(l)

ans = 0
for i in range(N):
    target = graph[i]
    counter = Counter(target)
    for k in sorted(counter.keys()):
        if k > 1270:
            break
        elif k == 1270:
            ans += counter[k] * (counter[k] - 1) // 2
        else:
            ans += counter[k] * counter[2540 - k]
print(ans)
