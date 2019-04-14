H, W = map(int, input().split())
grid = []
for i in range(H):
    grid.append(input())

if H == 1:
    print("#" * W)

elif H == 2:
    print("#" * W)
    tmp = ""
    for i in range(W):
        if i % 2 == 0:
            tmp += "."
        else:
            tmp += "#"
    print(tmp)

elif H == 3:
    for i in range(H):
        tmp = ""
        for j in range(W):
            if i == 0:
                tmp += "#"
            elif j == 0 or j == W - 1:
                tmp += "#"
            else:
                tmp += "."
        print(tmp)
else:
    for i in range(H):
        tmp = ""
        for j in range(W):
            if i == 0:
                tmp += "#"
            elif i == 1 and j == W // 2:
                tmp += "#"
            elif j == 0 or j == W - 1:
                tmp += "#"
            elif j == W // 2:
                tmp += "."
            elif i % 2 == 0:
                tmp += "#"
            else:
                tmp += "."
        print(tmp)
