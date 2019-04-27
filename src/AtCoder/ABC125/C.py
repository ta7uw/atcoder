from fractions import gcd

N = int(input())
a_list = list(map(int, input().split()))

gcd_num = a_list[0]
for a in a_list[1:]:
    gcd_num = gcd(gcd_num, a)

b_list = []

for a in a_list:
    b_list.append(a // gcd_num)

first = False
b_list.sort(reverse=True)
gcd_b = b_list[0]
for i, b in enumerate(b_list[1:]):
    tmp = gcd(gcd_b, b)
    if tmp == 1:
        if not first:
            first = True
            if i == 0:
                gcd_b = max(gcd_b, b)
            gcd_b = gcd_b
        else:
            gcd_b = 1
            break
    else:
        gcd_b = tmp
first = False
gcd_b3 = b_list[1]
b_list.append(b_list[0])

for i, b in enumerate(b_list[1:]):
    tmp = gcd(gcd_b3, b)
    if tmp == 1:
        if not first:
            first = True
            gcd_b3 = gcd_b3
        else:
            gcd_b3 = 1
            break
    else:
        gcd_b3 = tmp

print(gcd_num * max(gcd_b, gcd_b3))
