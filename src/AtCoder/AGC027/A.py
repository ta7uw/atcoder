N, x = map(int, input().split())
a_list = list(map(int, input().split()))
 
a_list.sort()
sum_num = 0
for i in range(N):
    item = a_list[i]
    if x >= item:
        if i != N-1:
            sum_num += 1
            x -= item
        elif x == item:
            sum_num += 1
            x -= item
    else:
       break
print(sum_num)
