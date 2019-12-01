N = int(input())
S = input()

ans = float("inf")
import string

alpha = string.ascii_uppercase
alpha += alpha
for i in range(N - 3):
    s = S[i:i + 4]
    cnt = 0

    tmp = 0
    a = alpha.index(s[0])
    tar = s[0]
    while tar != "A":
        a += 1
        tmp += 1
        tar = alpha[a]
    tmp2 = 0
    a = alpha.index(s[0])
    tar = s[0]
    while tar != "A":
        a -= 1
        tmp2 += 1
        tar = alpha[a]

    cnt += min(tmp, tmp2)

    tmp = 0
    a = alpha.index(s[1])
    tar = s[1]
    while tar != "C":
        a += 1
        tmp += 1
        tar = alpha[a]
    tmp2 = 0
    a = alpha.index(s[1])
    tar = s[1]
    while tar != "C":
        a -= 1
        tmp2 += 1
        tar = alpha[a]

    cnt += min(tmp, tmp2)

    tmp = 0
    a = alpha.index(s[2])
    tar = s[2]
    while tar != "T":
        a += 1
        tmp += 1
        tar = alpha[a]
    tmp2 = 0
    a = alpha.index(s[2])
    tar = s[2]
    while tar != "T":
        a -= 1
        tmp2 += 1
        tar = alpha[a]

    cnt += min(tmp, tmp2)

    tmp = 0
    a = alpha.index(s[3])
    tar = s[3]
    while tar != "G":
        a += 1
        tmp += 1
        tar = alpha[a]
    tmp2 = 0
    a = alpha.index(s[3])
    tar = s[3]
    while tar != "G":
        a -= 1
        tmp2 += 1
        tar = alpha[a]

    cnt += min(tmp, tmp2)
    ans = min(ans, cnt)
print(ans)
