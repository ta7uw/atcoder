N, M = map(int, input().split())
x_list = list(map(int, input().split()))

x_list.sort()
ans = 0

margin = [0] * (M - 1)
f = x_list[0]
for i in range(1, M):
    margin[i - 1] = x_list[i] - f
    f = x_list[i]
margin = sorted(enumerate(margin), key=lambda x: (-x[1], x[0]))
cnt = [0]
for i, v in margin:
    if len(cnt) == N:
        break
    cnt.append(i + 1)

if len(cnt) == 1:
    p = -1
    for i, x in enumerate(x_list):
        if i == 0:
            p = x_list[0]
        else:
            ans += x_list[i] - p
            p = x_list[i]
    print(ans)
    exit()
start = 0
prev = x_list[0]
cnt.append(M)
cnt.sort()
for i, c in enumerate(cnt[1:]):
    for j in range(start, c):
        ans += x_list[j] - prev
        prev = x_list[j]
    if c != M:
        start = c
        prev = x_list[c]
print(ans)
