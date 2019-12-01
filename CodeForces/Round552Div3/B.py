N = int(input())
a_list = list(map(int, input().split()))

a_set = set(a_list)
b_list = list(a_set)
b_list.sort()

if len(b_list) > 3:
    print(-1)
elif len(b_list) == 3:
    mid = b_list[1]
    if abs(mid - b_list[0]) == abs(mid - b_list[2]):
        for a in a_list:
            if a in b_list:
                continue
            else:
                print(-1)
                exit()
        print(mid - b_list[0])
    else:
        print(-1)
elif len(b_list) == 2:
    if (b_list[1] - b_list[0]) % 2 == 0:
        print((b_list[1] - b_list[0]) // 2)
    else:
        print(b_list[1] - b_list[0])
else:
    for a in a_list:
        if b_list[0] == a:
            continue
        else:
            print(-1)
            exit()
    print(0)
