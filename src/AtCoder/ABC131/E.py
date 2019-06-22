N, K = map(int, input().split())

i = 1
tmp = (N - 1) * (N - 2) // 2
if K > tmp:
    print(-1)
    exit()
ans = []
for j in range(2, N + 1):
    ans.append((i, j))

if tmp != K:
    for i in range(2, N + 1):
        for j in range(i + 1, N + 1):
            if i == j:
                continue
            else:
                ans.append((i, j))
                tmp -= 1
                if tmp == K:
                    break
        if tmp == K:
            break
if tmp == K:
    print(len(ans))
    for a in ans:
        print(a[0], a[1])
else:
    print(-1)
