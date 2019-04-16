N = int(input())
a_list = list(map(int, input().split()))

a_list.sort()
min_a = a_list[0]
max_a = a_list[-1]

cand = [0]
if (max_a + min_a) % 2 == 0:
    cand.append((max_a - min_a) // 2)
cand.append(max_a - min_a)

mean = a_list[N // 2]
if N == 2:
    for c in cand:
        d = a_list[0] + c
        d2 = a_list[-1] - c
        if d == d2:
            print(c)
            exit()
    print(-1)
    exit()

for c in cand:
    tmp = []
    for a in a_list:
        if mean == a:
            tmp.append(a)
        elif mean > a:
            tmp.append(a + c)
        else:
            tmp.append(a - c)
    at = tmp[0]
    f = True
    for t in tmp:
        if t != at:
            f = False
    if f:
        print(c)
        exit()
print(-1)
