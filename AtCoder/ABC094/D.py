n = int(input())
a_list = [i for i in list(map(int, input().split()))]

a_list.sort()
max_num = a_list.pop(-1)
margin = max_num
r = 0
for a in a_list:
    m = abs(max_num/2 - a)
    if margin >= m:

        margin = m
        r = a

print(str(max_num) + " " + str(r))
