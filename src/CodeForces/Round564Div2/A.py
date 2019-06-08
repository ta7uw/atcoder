x, y, z = map(int, input().split())

if z != 0:
    if abs(x - y) <= z:
        print("?")
    else:
        if x > y:
            print("+")
        else:
            print("-")

else:
    if x == y:
        print("0")
    elif x > y:
        print("+")
    else:
        print("-")
