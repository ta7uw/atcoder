N = int(input())
a_list = list(map(int, input().split()))

for i in range(N, 0, -1):

    j = i
    sum_num = 0
    while j <= N:
        a = a_list[j - 1]
        if j != i:
            sum_num += a
        if i == 1:
            j += 1
        else:
            j += i
    if sum_num % 2 == 0:
        if a_list[i - 1] == 0:
            continue
        else:
            a_list[i - 1] = 1
    else:
        if a_list[i - 1] == 1:
            a_list[i - 1] = 0
        else:
            a_list[i - 1] = 1

ans = sum(a_list)
print(ans)

for i in range(1, N + 1):
    if a_list[i - 1] != 0:
        print(i)
