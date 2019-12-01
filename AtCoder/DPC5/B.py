N, K = map(int, input().split())
a_list = list(map(int, input().split()))
sum_list = []

for i in range(N):
    for j in range(i, N):
        sum_list.append(sum(a_list[i:j+1]))
ans = 0
count = 0
tmp = []
for i in range(40, -1, -1):
    for s in sum_list:
        check_num = 1 << i
        logical_and = check_num & s

        if logical_and != 0:
            count += 1

    if count >= K:
        ans += 1 << i
        tmp = [x for x in sum_list if (1 << i) & x != 0]
        sum_list = tmp[:]
    count = 0
print(ans)

