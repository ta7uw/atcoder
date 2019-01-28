from collections import deque, defaultdict

N, M = map(int, input().split())
ab = []
for _ in range(N + M - 1):
    a, b = map(int, input().split())
    ab.append((a, b))

out = defaultdict(list)
in_cnt = defaultdict(int)
rev = defaultdict(list)
for a, b in ab:
    out[a].append(b)
    in_cnt[b] += 1
    rev[b].append(a)

queue = deque(i for i in range(1, N + 1) if in_cnt[i] == 0)
sorted_ans = []

while len(queue) != 0:
    v = queue.popleft()
    sorted_ans.append(v)
    for v2 in out[v]:
        in_cnt[v2] -= 1
        if in_cnt[v2] == 0:
            queue.append(v2)

order = [0] + [i + 1 for i, v in sorted(enumerate(sorted_ans), key=lambda x: x[1])]
ans = [0] * (N + 1)
ans[sorted_ans[0] + 1] = 0

for v in sorted_ans[:0:-1]:
    ans[v] = max((order[v2], v2) for v2 in rev[v])[1]

for a in ans[1:]:
    print(a)
