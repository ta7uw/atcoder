N = int(input())
a_list = [int(input()) for _ in range(N)]

man = {}
for a in a_list:
    if a in man:
        man[a] += 1
    else:
        man[a] = 1

sorted_man = sorted(man.items(), key=lambda x: -x[0])
ans = 0
minus_1 = 0
remain2 = 0
for a, cnt in sorted_man:
    if a == 4:
        ans += cnt
    if a == 3:
        ans += cnt
        if 1 in man:
            if man[1] >= cnt:
                minus_1 += cnt
            else:
                minus_1 += man[1]
    if a == 2:
        if cnt % 2 == 0:
            ans += cnt // 2
        else:
            ans += cnt // 2
            remain2 += 2
    if a == 1:
        cnt -= minus_1
        cnt += remain2
        remain2 -= remain2
        if cnt > 0:
            ans += cnt // 4
            if cnt % 4 != 0:
                ans += 1

if remain2 > 0:
    ans += 1
print(ans)
