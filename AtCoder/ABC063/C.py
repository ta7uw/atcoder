N = int(input())
s_list = []
for i in range(N):
    s_list.append(int(input()))

sum_num = sum(s_list)

if sum_num % 10 != 0:
    print(sum_num)
    exit()
else:
    s_list.sort()
    tmp = sum_num
    for s in s_list:
        if s % 10 == 0:
            continue
        sum_num = tmp - s
        if sum_num % 10 != 0:
            print(sum_num)
            exit()
        sum_num = tmp
    print(0)

