L, R = map(int, input().split())

if (R - L + 1) >= 2019:
    print(0)
else:
    ans = float("inf")
    for i in range(L, R + 1):
        for j in range(L, R + 1):
            if i == j:
                continue
            else:
                ans = min(ans, (i * j) % 2019)
    print(ans)
