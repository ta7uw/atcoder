N, T = map(int, input().split())
a_list = list(map(int, input().split()))

min_num = 0
margin_list = []
for i in range(N):
    if i == 0:
        min_num = a_list[0]
    else:
        if min_num > a_list[i]:
            min_num = a_list[i]
        else:
            margin_list.append(a_list[i] - min_num)
max_num = max(margin_list)
print(margin_list.count(max_num))
