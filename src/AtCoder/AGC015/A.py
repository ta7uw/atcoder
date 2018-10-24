N, A, B = map(int, input().split())


margin = B - A
if N == 1 and margin >0:
    print(0)
    exit()


if margin < 0:
    print(0)
    exit()
elif margin == 0:
    print(1)
    exit()


print(margin * (N-2) + 1)

