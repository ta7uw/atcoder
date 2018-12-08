n = int(input())
a_list = [int(input()) for i in range(n)]
a_list.sort()
b_list = a_list[:-1]
print(a_list[-1] // 2 + sum(b_list))