T = int(input())

for t in range(T):
    P, Q = map(int, input().split())
    x_tar = [0 for i in range(Q + 2)]
    y_tar = [0 for i in range(Q + 2)]

    for i in range(P):
        tmp = input()
        tmp = tmp.split()
        x, y, d = tmp[0], tmp[1], tmp[2]
        x = int(x)
        y = int(y)
        if d == "W":
            x_tar[0] += 1
            x_tar[x] -= 1
        elif d == "E":
            x_tar[-1] -= 1
            x_tar[x + 1] += 1
        elif d == "N":
            y_tar[-1] -= 1
            y_tar[y + 1] += 1
        else:
            y_tar[0] += 1
            y_tar[y] -= 1

    for i in range(1, Q + 1):
        x_tar[i] += x_tar[i - 1]
        y_tar[i] += y_tar[i - 1]

    max_x = max(x_tar)
    max_y = max(y_tar)
    x_ans = 0
    y_ans = 0

    for i in range(Q + 1):
        x = x_tar[i]
        if x == max_x:
            x_ans = i
            break
    for i in range(Q + 1):
        y = y_tar[i]
        if y == max_y:
            y_ans = i
            break
    print("Case #{}: {} {}".format(t + 1, x_ans, y_ans))
