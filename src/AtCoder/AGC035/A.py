N = int(input())
a_list = list(map(int, input().split()))

tmp = set()
for a in a_list:
    tmp.add(a)

if a_list.count(0) == N:
    print("Yes")
else:
    if len(tmp) == 2 and a_list.count(0) == N // 3:
        print("Yes")
    elif len(tmp) == 3 and a_list.count(0) == 0:
        b = list(tmp)
        if b[0] ^ b[1] == b[2] and a_list.count(b[0]) == N // 3 \
                and a_list.count(b[1]) == N // 3 and a_list.count(b[2]) == N // 3:
            print("Yes")
        else:
            print("No")
    else:
        print("No")
