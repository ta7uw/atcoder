n, k = map(int, input().split())
a_list = []
b_list = []
for i in range(n):
    a, b = map(int, input().split())
    a_list.append(a)
    b_list.append(b)

dic = {}
for i in range(n):
    a = a_list[i]
    b = b_list[i]
    if a in dic.keys():
        tmp = dic[a]
        dic[a] = tmp + b
    else:
        dic[a] = b
count = 0
sorted_dic = sorted(dic.items())
for a, b in sorted_dic:
    count += b
    if count >= k:
        print(a)
        exit()