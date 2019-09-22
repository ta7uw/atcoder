x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())
x5, y5, x6, y6 = map(int, input().split())

if x3 <= x1 and x2 <= x6 and (y3 <= y1 and y2 <= y4) and (y5 <= y1 and y2 <= y6):
    if x1 <= x5 <= x4 <= x2:
        print("NO")
        exit()
if x5 <= x1 and x2 <= x4 and (y3 <= y1 and y2 <= y4) and (y5 <= y1 and y2 <= y6):
    if x1 <= x3 <= x6 <= x2:
        print("NO")
        exit()

if y3 <= y1 and y2 <= y6 and (x3 <= x1 and x2 <= x4) and (x5 <= x1 and x2 <= x6):
    if y1 <= y5 <= y4 <= y2:
        print("NO")
        exit()

if y5 <= y1 and y2 <= y4 and (x3 <= x1 and x2 <= x4) and (x5 <= x1 and x2 <= x6):
    if y1 <= y3 <= y6 <= y2:
        print("NO")
        exit()

if x3 <= x1 and x2 <= x4 and y3 <= y1 and y2 <= y4:
    print("NO")
    exit()
if x5 <= x1 and x2 <= x6 and y5 <= y1 and y2 <= y6:
    print("NO")
    exit()
print("YES")
