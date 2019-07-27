N = int(input())
a_list = list(map(int, input().split()))
b_list = list(map(int, input().split()))

ans = 0
for i in range(N):
    b = b_list[i]
    a1 = a_list[i]
    a2 = a_list[i+1]

    if b >= a1:
        tmp = a1
        ans += tmp
        b -= tmp
        if b > 0:
            if b >= a2:
                tmp2 = a2
                ans += tmp2
                a_list[i+1] -= tmp2
            else:
                ans += b
                a_list[i+1] -= b
    else:
        ans += b

print(ans)
