N = int(input())
a_list = list(map(int, input().split()))

a_list.sort()
a_list.reverse()
sum_num = 0
count = 0
for i in range(3*N):
    if (i+1) % 2 == 0:
        sum_num += a_list[i]
        count += 1
    if count == N:
        break
print(sum_num)
