N = int(input())
a_list = list(map(int, input().split()))

ans = []
for i in range(N):
    a = a_list[i]
    if i == 0:
        for j in range(1, N):
            if j % 2 == 0:
                a += a_list[j]
            else:
                a -= a_list[j]
        ans.append(a)
    else:
        a = a_list[i - 1]
        ans.append(2 * (a - ans[-1] // 2))

for a in ans:
    print(a)
