N = int(input())
a_list = list(map(int, input().split()))

odd_sum = [0]
even_sum = [0]

for i in range(N):
    if i % 2 == 0:
        odd_sum.append(odd_sum[-1] + a_list[i])
        even_sum.append(even_sum[-1] - a_list[i])
    else:
        odd_sum.append(odd_sum[-1] - a_list[i])
        even_sum.append(even_sum[-1] + a_list[i])

ans = []
for i in range(N):
    a = a_list[i]

    if i % 2 == 0:
        a += (odd_sum[-1] - odd_sum[i + 1])
        a += even_sum[i]
    else:
        a += (even_sum[-1] - even_sum[i + 1])
        a += odd_sum[i]
    print(a)
