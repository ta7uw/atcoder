import sys

N, M = map(int, sys.stdin.readline().split())
a_list = list(map(int, sys.stdin.readline().split()))
items = []
for i in range(M):
    items.append(tuple(map(int, sys.stdin.readline().split())))


from collections import defaultdict

tar = defaultdict(int)
for a in a_list:
    tar[a] += 1

for i in range(M):
    b, c = items[i]
    tar[c] += b

tar = sorted(tar.items(), key=lambda x: -x[0])

cnt = 0
ans = 0
for k, v in tar:
    if cnt + v <= N:
        cnt +=v
        ans += k*v
    else:
        ans += k*(N-cnt)
        cnt = N
    if cnt >= N:
        break
print(ans)
