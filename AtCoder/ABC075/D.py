N, K = map(int, input().split())
xy = []
for _ in range(N):
    xy.append(tuple(map(int, input().split())))

xy.sort()
ans = float("inf")
for i in range(N):
    for j in range(i + 1, N):
        x = xy[j][0] - xy[i][0]
        y_list = [xy[1] for xy in xy[i:j + 1]]
        y_list.sort()
        for k in range(len(y_list) - K + 1):
            y = y_list[k + K - 1] - y_list[k]
            tmp = x * y
            if ans > tmp:
                ans = tmp

print(ans)
