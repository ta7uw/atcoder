N = int(input())
a_list = [int(input()) for _ in range(N)]

b_list = a_list.copy()
b_list.sort(reverse=True)
max_num = max(b_list)

for i in range(N):

    a = a_list[i]

    if a != max_num:
        print(max_num)
    else:
        f = True
        cnt = 0
        for b in b_list:
            if a != b:
                print(b)
                f = False
                break
            else:
                cnt += 1
                if cnt >= 2:
                    break
        if f:
            print(b)
