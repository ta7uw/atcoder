a, b, c = map(int, input().split())

D = min(a // 3, b // 2, c // 2)
A, B, C = a - 3 * D, b - 2 * D, c - 2 * D

ans = D * 7
if A == 0 and C == 0 and B == 0:
    print(ans)

elif C == 0 and B == 0:
    if A == 1:
        print(ans + 1)
    else:
        print(ans + 2)

elif C == 0:
    if B == 1 and A == 1:
        print(ans + 2)
    elif B == 1 and A >= 2:
        print(ans + 3)
    elif B == 1 and A == 0:
        print(ans + 1)
    elif A == 0:
        print(ans + 1)
    elif A == 1:
        print(ans + 2)
    else:
        print(ans + 4)
elif C == 1:
    if B == 1:
        if A == 1:
            print(ans + 3)
        elif A == 0:
            print(ans + 2)
        else:
            print(ans + 4)

    elif B == 0:
        if A == 0:
            print(ans)
        elif A == 1:
            print(ans + 2)
        else:
            print(ans + 2)
    else:
        if A == 0:
            print(ans + 2)
        elif A == 1:
            print(ans + 3)
        elif A == 2:
            print(ans + 5)
        else:
            print(ans + 6)
else:
    if B == 0:
        if A == 0:
            print(ans + 1)
        elif A == 1:
            print(ans + 2)
        else:
            print(ans + 3)
    if B == 1:
        if A == 0:
            print(ans + 2)
        elif A == 1:
            print(ans + 4)
        elif A == 2:
            print(ans + 5)
        else:
            print(ans + 6)
    else:
        if A == 0:
            print(ans + 2)
        elif A == 1:
            print(ans + 5)
        elif A == 2:
            print(ans + 6)
