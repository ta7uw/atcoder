n = int(input())
a_list = list(map(int, input().split()))

b_list_even = []
b_list_odd = []
for i, a in enumerate(a_list , start=1):
    if i % 2 == 0:
        b_list_even.append(a)
    else:
        b_list_odd.append(a)


if n % 2 != 0:
    b_list_odd.reverse()
    b_list = b_list_odd + b_list_even
else:
    b_list_even.reverse()
    b_list = b_list_even + b_list_odd

print(" ".join(map(str, b_list)))

