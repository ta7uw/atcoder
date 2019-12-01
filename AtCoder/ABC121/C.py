N, M = map(int, input().split())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))

items = sorted(items, key=lambda x: x[0])
cnt = 0
ans = 0
for item in items:
    a, b = item
    if cnt + b > M:
        tmp = M - cnt
        ans += a * tmp
        print(ans)
        exit()
    else:
        ans += a * b
        cnt += b
    if cnt >= M:
        print(ans)
        exit()
