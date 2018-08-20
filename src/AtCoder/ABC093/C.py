input_list = list(map(int, input().split()))
input_list.sort()
max_num = input_list[2]
second = input_list[1]
min_num = input_list[0]
 
count = 0
margin = max_num - second
margin2 = max_num - min_num
 
if margin % 2 == 0:
    count += margin / 2
 
else:
    count += margin // 2
    if margin2 % 2 == 0:
        count += 1
        margin2 -= 1
 
    else:
        count += 1
        margin2 -= 1
 
if margin2 % 2 ==0:
    count += margin2 / 2
 
else:
    count += margin2 // 2
    count += 2
 
print(int(count))

