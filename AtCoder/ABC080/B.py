N = int(input())
tmp = N
sum_digit = 0
while tmp > 0:
    sum_digit += tmp % 10
    tmp //= 10
if N % sum_digit == 0:
    print("Yes")
else:
    print("No")
