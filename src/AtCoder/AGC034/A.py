N, A, B, C, D = map(int, input().split())
S = list(input())

# 3マス空きがあるか
white = []
for i in range(N - 2):
    if S[i] == "." == S[i + 1] == S[i + 2]:
        white.append(i + 1)

if C > D:
    # Aからスタート
    i = A - 1
    T = S.copy()
    T[B - 1] = "#"
    while C - 1 != i:
        if T[i + 1] == ".":
            i += 1
        elif T[i + 2] == ".":
            i += 2
        elif i + 1 == B - 1 or i + 2 == B - 1:
            es = False
            for w in white:
                if i < w:
                    if w <= D - 1:
                        es = True
            if es:
                i = B - 1
            else:
                break
        else:
            break
    if i == C - 1:
        print("Yes")
        exit()
else:
    i = B - 1
    T = S.copy()
    while D - 1 != i:
        if T[i + 1] == ".":
            i += 1
        elif T[i + 2] == ".":
            i += 2
        else:
            break
    if i == D - 1:
        T2 = S.copy()
        T2[D - 1] = "#"
        j = A - 1
        while C - 1 != j:
            if T[j + 1] == ".":
                j += 1
            elif T[j + 2] == ".":
                j += 2
            else:
                break
        if j == C - 1:
            print("Yes")
            exit()
print("No")
