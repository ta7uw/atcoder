N = int(input())
l_list = list(map(int, input().split()))
l_list.sort(reverse=True)
maxnum = l_list[0]
sum_num = sum(l_list[1:])

if maxnum < sum_num:
    print("Yes")
else:
    print("No")
