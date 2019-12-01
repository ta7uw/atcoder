N = int(input())
a_list = list(map(int, input().split()))

b_list = []

c_list = []
cnt = 0
for a in a_list:
    if a <= 0:
        cnt += 1
    c_list.append(abs(a))

if cnt % 2 != 0:
    print(sum(c_list) - 2 * min(c_list))
else:
    print(sum(c_list))
