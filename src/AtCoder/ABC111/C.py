n = int(input())
v_list = list(map(int, input().split()))
 
min_num = 0
 
even = {}
odd = {}
 
for i, v in enumerate(v_list):
    if i % 2 == 0:
        if v in even:
            even[v] += 1
        else:
            even[v] = 1
    else:
        if v in odd:
            odd[v] += 1
        else:
            odd[v] = 1
 
even_max = sorted(even.items(), key=lambda x: -x[1])
odd_max = sorted(odd.items(), key=lambda x: -x[1])
 
even_num = even_max[0][0]
odd_num = odd_max[0][0]
 
if odd_num == even_num:
    if len(odd_max) == 1 and len(even_max) == 1:
        odd_num = 10 ** 5 + 1
    elif len(odd_max) == 1:
        even_num = even_max[1][0]
    elif len(even_max) == 1:
        odd_num = odd_max[1][0]
    else:
        first_e = even_max[0][1]
        first_d = odd_max[0][1]
        if first_e > first_d:
            odd_num = odd_max[1][0]
        elif first_e < first_d:
            even_num = even_max[1][0]
        elif first_e == first_d:
            second_e = even_max[1][1]
            second_d = odd_max[1][1]
            if second_e >= second_d:
                even_num = even_max[1][0]
            else:
                odd_num = odd_max[1][0]
 
for i, v in enumerate(v_list):
    if i % 2 == 0:
        if v != even_num:
            min_num += 1
    else:
        if v != odd_num:
            min_num += 1
print(min_num)
