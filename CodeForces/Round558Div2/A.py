N, M = map(int, input().split())

if M == 1 or M == 0:
    print(1)
else:
    M -= 1
    N -= 1
    ans = 1
    while M > 0 and N >= 2:
        N -= 2
        ans += 1
        M -= 1
        if N == 0:
            ans -= 1
    print(ans - M)
