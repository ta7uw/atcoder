N, M, H = map(int, input().split())
a_list = list(map(int, input().split()))
b_list = list(map(int, input().split()))

items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))
ans = []
for i in range(N):
    tmp = []
    for j in range(M):
        now = items[i][j]
        if now == 0:
            tmp.append(0)
        else:
            a = a_list[j]
            b = b_list[i]
            tmp.append(min(a, b))
    ans.append(tmp)
for a in ans:
    for t in a:
        print(t, end=" ")
    print()
