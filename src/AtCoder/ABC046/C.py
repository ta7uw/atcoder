n = int(input())
t_list = []
a_list = []
for i in range(n):
    t, a = map(int, input().split())
    t_list.append(t)
    a_list.append(a)

t_num = t_list[0]
a_num = a_list[0]
for i in range(1, n):
    t, a = t_list[i], a_list[i]
    num = max((a_num+a-1)//a, (t_num+t-1)//t)
    t_num = num * t
    a_num = num * a
print(t_num + a_num)
