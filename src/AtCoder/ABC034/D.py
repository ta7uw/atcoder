N, K = map(int, input().split())
items = []
for _ in range(N):
    w, p = map(int, input().split())
    items.append((w, p))
ok = 0
ng = 101
while ng - ok > 1e-10:
    mid = (ok + ng) / 2
    tmp = sorted([w * (p - mid) for w, p in items], reverse=True)
    if sum(tmp[:K]) >= 0:
        ok = mid
    else:
        ng = mid
print(ok)
