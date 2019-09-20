Q = int(input())

ans = []
for q in range(Q):
    c, m, x = map(int, input().split())
    a = 0
    if c >= x and m >= x:
        a += x
        c -= x
        m -= x
        if c > m:
            tmp = c + m
            if c >= tmp // 3 and m >= tmp // 3:
                a += tmp // 3
            else:
                a += min(m, c//2)

        elif c == m:
            a += (c + m) // 3
        else:
            tmp = c + m
            if c >= tmp // 3 and m >= tmp // 3:
                a += tmp // 3
            else:
                a += min(c, m//2)
    else:
        a = min(c, m)
    ans.append(a)
for a in ans:
    print(a)
