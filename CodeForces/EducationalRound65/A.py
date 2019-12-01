T = int(input())
for t in range(T):
    N = int(input())
    S = input()

    eight = S.count("8")

    if eight >= 1:
        flg = False
        for i in range(N):
            s = S[i]
            if s == "8" and N - (i + 1) >= 10:
                flg = True
                print("YES")
                break
        if not flg:
            print("NO")
    else:
        print("NO")
