Q = int(input())
items = []
for i in range(Q):
    items.append(tuple(map(int, input().split())))


def f(x, y, yen, cnt):
    if x == y:
        if cnt % 2 == 0:
            tmp = cnt / 2
            x += yen * tmp
            y += yen * tmp
        else:
            x += yen * ((cnt + 1) // 2)
            y += yen * (cnt // 2)

    else:
        margin = x - y
        if margin <= yen * cnt:
            tmp = margin / yen
            cnt -= tmp
            y = x

            if cnt % 2 == 0:
                tmp = cnt / 2
                x += yen * tmp
                y += yen * tmp
            else:
                x += yen * ((cnt + 1) // 2)
                y += yen * (cnt // 2)
        else:
            y += yen * cnt
    return x, y


for a, b, c in items:
    yen = 100 * a + 10 * b + c
    if yen % 2 == 0:
        x, y = 0, 0
        x, y = f(x, y, 100, a)
        x, y = f(x, y, 10, b)
        x, y = f(x, y, 1, c)
        if x == y:
            print("Yes")
        else:
            print("No")
    else:
        print("No")
