N = int(input())
S = input()

prev = ""
ans = 0
deleted = set()
flg = True
i = 0
while i <= N - 1:
    if flg and (i - ans) % 2 == 0:
        prev = S[i]
        i += 1
    else:
        if prev == S[i]:
            flg = False
            ans += 1
            deleted.add(i)
            i += 1
            continue
        else:
            i += 1
            flg = True

T = ""

for i in range(N):
    if i in deleted:
        continue
    else:
        T += S[i]
if len(T) % 2 == 1:
    print(ans + 1)
    print(T[:-1])
else:
    print(ans)
    print(T)
