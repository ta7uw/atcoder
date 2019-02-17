N = int(input())

for i in range(1, N + 1):
    s = ""
    if i % 2 == 0:
        s += "a"
    if i % 3 == 0:
        s += "b"
    if i % 4 == 0:
        s += "c"
    if i % 5 == 0:
        s += "d"

    if i % 6 == 0:
        s += "e"

    if len(s) == 0:
        print(i)
    else:
        print(s)
