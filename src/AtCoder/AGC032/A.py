N = int(input())
b_list = list(map(int, input().split()))

ans = []
while len(b_list) > 0:
    f = -1
    for i in range(len(b_list)):
        if b_list[i] == i + 1:
            f = i
    if f == -1:
        print(-1)
        exit()
    ans.append(b_list[f])
    b_list.pop(f)

ans = reversed(ans)
for a in ans:
    print(a)
