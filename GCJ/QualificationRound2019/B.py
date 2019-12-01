N = int(input())
cases = []
for i in range(N):
    n = int(input())
    s = input()
    cases.append((n, s))

ans = []
for n, s in cases:
    tmp = ""
    for i in range(2 * n - 2):
        if s[i] == "E":
            tmp += "S"
        else:
            tmp += "E"
    ans.append(tmp)

for i, a in enumerate(ans):
    i += 1
    tmp = "Case #" + str(i) + ":"
    print(tmp, a)
