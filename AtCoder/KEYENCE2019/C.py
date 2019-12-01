N = int(input())
a_list = tuple(map(int, input().split()))
b_list = tuple(map(int, input().split()))
a_sum = sum(a_list)
b_sum = sum(b_list)

if b_sum > a_sum:
    print(-1)
    exit()

minus = {}
plus = {}
for i in range(N):
    a = a_list[i]
    b = b_list[i]
    tmp = a - b
    if tmp < 0:
        if tmp in minus:
            minus[tmp] += 1
        else:
            minus[tmp] = 1
    else:
        if tmp in plus:
            plus[tmp] += 1
        else:
            plus[tmp] = 1

minus = sorted(minus.items(), key= lambda x:x[0])
plus = sorted(plus.items(), key= lambda x:-x[0])
ans = 0
changed = 0
for k, v in minus:
    ans += v
    changed += (k * v)
if changed <0:
    for k, v in plus:
        for j in range(1, v+1):
            ans += 1
            changed += k
            if changed >= 0:
                print(ans)
                exit()
print(ans)