from collections import deque, defaultdict
import sys

N = int(input())
ab = []
for i in range(N - 1):
    ab.append(tuple(map(int, input().split())))

c_list = list(map(int, input().split()))
c_list.sort()
c_que = deque(c_list)

cnt = defaultdict(int)
outs = defaultdict(list)
for a, b in ab:
    cnt[a - 1] += 1
    cnt[b - 1] += 1
    outs[a - 1].append(b - 1)
    outs[b - 1].append(a - 1)

cnt = sorted(cnt.items(), key=lambda x: -x[1])
top = cnt[0][0]
tar = defaultdict(lambda: 0)

sys.setrecursionlimit(10 ** 9)
visit = [False] * N


def dfs(start):
    tmp = []
    visit[start] = True
    for v2 in outs[start]:
        if visit[v2]:
            continue
        q = c_que.pop()
        tar[v2] = q
        tmp.append(v2)
    for v2 in tmp:
        if visit[v2]:
            continue
        dfs(v2)


tar[top] = c_que.pop()
dfs(top)
ans = 0
for a, b in ab:
    a -= 1
    b -= 1
    ans += min(tar[a], tar[b])
print(ans)
for i in range(N):
    print(tar[i], end=" ")
