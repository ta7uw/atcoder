N, K = map(int, input().split())
a_list = list(map(int, input().split()))

left = 0
right = 0

bored = []
prev = 0
cnt = 1
for i in range(N):
    a = a_list[i]
    if i != 0:
        if a == prev:
            cnt += 1
        else:
            bored.append(cnt)
            cnt = 1
    prev = a
if cnt != 0:
    bored.append(cnt)

ok = max(bored)
ng = 0

while ok - ng > 1:
    mid = (ok + ng) // 2
    tmp = 0
    for b in bored:
        c = 0
        while b // (c + 1) > mid:
            c += 1
        tmp += c
    if tmp <= K:
        ok = mid
    else:
        ng = mid
print(ok)
