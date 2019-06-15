N = int(input())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))


ans = 0
res = []
for i in range(N):
    for j in range(N):
        if i == j:
            continue
        x1, y1 = items[i]
        x2, y2 = items[j]
        res.append((x1-x2, y1 -y2))

tar = []
for i in range(len(res)):
    x, y = res[i]
    cnt = 0
    for j in range(len(res)):
        if i == j:
            continue
        if x == res[j][0] and y == res[j][1]:
            cnt += 1
    if ans <= cnt:
        ans = cnt
        tar.append((x, y))


ans2 = 0
tar = list(set(tar))
for t in tar:
    cnt2 = 0
    for i in range(N):
        x, y = items[i]
        for j in range(N):
            if i == j:
                continue
            x2, y2 = items[j]
            if x - t[0] == x2 and y - t[1] == y2:
                cnt2 += 1
                break

    ans2 = max(ans2, cnt2)

print(N - ans2)
