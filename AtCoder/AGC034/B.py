S = list(input())
N = len(S)

i = 0
ans = 0
T = list(reversed(S))
bc_cnt = 0
bc = False
for i in range(N):
    t = T[i]
    if bc:
        if t == "A":
            ans += bc_cnt
        elif t == "C" and i < N - 1 and T[i + 1] == "B":
            bc_cnt += 1
        elif t == "B" and T[i - 1] == "C":
            continue
        else:
            bc_cnt = 0
            bc = False

    elif t == "C" and i < N - 1 and T[i + 1] == "B":
        bc = True
        bc_cnt += 1
print(ans)
