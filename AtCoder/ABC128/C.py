N, M = map(int, input().split())
items = []
for i in range(M):
    items.append(tuple(map(int, input().split())))
p_list = list(map(int, input().split()))

tar = []


def brute_force(s, remain):
    if remain == 0:
        tar.append(s)
    else:
        brute_force(s + "0", remain - 1)
        brute_force(s + "1", remain - 1)


brute_force("", N)

ans = 0
for T in tar:
    flag = True
    for i in range(M):
        p = p_list[i]
        k = items[i][0]
        s_list = items[i][1:]
        tmp = 0
        for s in s_list:
            t = T[s - 1]
            if t == "1":
                tmp += 1
        if tmp % 2 == p:
            continue
        else:
            flag = False
            break
    if flag:
        ans += 1

print(ans)
