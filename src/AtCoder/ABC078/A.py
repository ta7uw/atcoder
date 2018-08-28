XY = input().split()
X = int(XY[0], 16)
Y = int(XY[1], 16)

if X == Y :
    print("=")
else:
    print("<" if X < Y else ">")
