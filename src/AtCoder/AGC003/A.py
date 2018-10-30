S = input()

n = S.count("N")
s = S.count("S")
e = S.count("E")
w = S.count("W")

home = False
if n and s:
    if e and w:
        print("Yes")
    elif not e and not w:
        print("Yes")
    else:
        print("No")

elif not n and not s:
    if e and w:
        print("Yes")
    elif not e and not w:
        print("Yes")
    else:
        print("No")

else:
    print("No")
