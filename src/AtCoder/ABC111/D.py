N = int(input())
xy = []
max_num = 0

bad = False
for i in range(N):
    XY = list(map(int, input().split()))
    xy.append(XY)
parity = sum(xy[0]) % 2
for X, Y in xy:
    if abs(X) + abs(Y) >= max_num:
        max_num = abs(X) + abs(Y)

    if (abs(X) + abs(Y)) % 2 != parity:
        bad = True

if bad:
    print(-1)
else:
    print(max_num)
    print("1 "*max_num)
    for x, y in xy:
        answer = ("U" if y > 0 else "D") * abs(y) + ("R" if x > 0 else "L") * abs(x)
        answer += "LR" * ((max_num - len(answer)) // 2)
        print(answer)

