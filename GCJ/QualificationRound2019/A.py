N = int(input())
t_list = [int(input()) for _ in range(N)]

ans = []

for t in t_list:
    tmp = str(t)
    n = len(str(t))
    A = ""
    B = ""
    for i in range(n):
        s = tmp[i]
        if s == "4":
            A += "1"
            B += "3"
        else:
            A += s
            B += "0"

    cnt = -1
    for c, b in enumerate(B):
        if b == "0":
            cnt = c
        else:
            break
    if cnt != -1:
        B = B[cnt + 1:]

    ans.append((A, B))

for i, a in enumerate(ans):
    i += 1
    tmp = "Case #" + str(i) + ":"
    print(tmp, a[0], a[1])
