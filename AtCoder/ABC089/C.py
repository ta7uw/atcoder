N = int(input())
s = [input() for _ in range(N)]

a = [0] * 5
for i in range(N):
    if s[i][0] == "M":
        a[0] += 1
    elif s[i][0] == "A":
        a[1] += 1
    elif s[i][0] == "R":
        a[2] += 1
    elif s[i][0] == "C":
        a[3] += 1
    elif s[i][0] == "H":
        a[4] += 1

S = 0
for k in range(5):
    for l in range(k + 1, 5):
        for m in range(l + 1, 5):
            S += a[k] * a[l] * a[m]

print(S)
