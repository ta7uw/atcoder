N, A = map(int, input().split())
tmp = N // 3
if A <= 3:
    if A == 0:
        print(0, 0)
    else:
        print(1, A)
else:
    print((A + 3 - 1) // 3, min(tmp, A))
