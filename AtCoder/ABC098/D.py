n = int(input())
a_list = list(map(int, input().split()))

count = 0
l = 0
r = 0

sum_num = a_list[0]
xor_num = a_list[0]

while l < n and r < n:
    if sum_num == xor_num:
        count += r - l + 1
        r += 1
        if r < n:
            sum_num += a_list[r]
            xor_num ^= a_list[r]
    else:
        if l < n :
            sum_num -= a_list[l]
            xor_num ^= a_list[l]
        l += 1


print(count)