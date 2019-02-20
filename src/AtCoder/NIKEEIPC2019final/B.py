N, M, K = map(int, input().split())
a_list = list(map(int, input().split()))
b_list = list(map(int, input().split()))

if N == M:
    for i in range(N):
        a = a_list[i]
        b = b_list[i]
        if a == b:
            continue
        elif a > b:
            print("Y")
            exit()
        else:
            print("X")
            exit()
    print("Same")
else:
    if N > M:
        print("Y")
    else:
        print("X")
