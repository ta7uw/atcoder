S = input()
K = int(input())


for i, s in enumerate(S):
    if s == "1":
        if i + 1 == K:
            print(1)
            exit()
    else:
        print(s)
        exit()


