N = int(input())
a_list = list(map(int, input().split()))

a_sum = sum(a_list)
min_num = float("inf")
r = []

for i in range(1, N):
    if len(r) == 0:
        r.append(a_list[0])
    else:
        r.append(r[i-2] + a_list[i-1])

    x = r[i-1]
    y = a_sum - x
    if min_num >= abs(x-y):
        min_num = abs(x-y)
print(min_num)
