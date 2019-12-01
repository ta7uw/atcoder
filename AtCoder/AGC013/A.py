N = int(input())
a_list = list(map(int, input().split()))

count = 0
c_list = []
increment = False
decrement = False

for i, a in enumerate(a_list):
    if i == 0:
        c_list.append(a)

    elif not increment and not decrement:
        if a > c_list[0]:
            c_list.append(a)
            increment = True
        elif a < c_list[0]:
            c_list.append(a)
            decrement = True
        else:
            continue
    else:
        if increment:
            if a >= c_list[-1]:
                c_list.append(a)
            else:
                c_list = [a]
                increment = False
                decrement = False
                count += 1
        else:
            if a <= c_list[-1]:
                c_list.append(a)
            else:
                c_list = [a]
                increment = False
                decrement = False
                count += 1

print(count+1)
