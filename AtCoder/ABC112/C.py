N = int(input())

in_list = []
x0, y0, h0 = 0, 0, 0
for i in range(N):
    xyh = list(map(int, input().split()))
    in_list.append(xyh)

for i in range(N):
    if in_list[i][2]:
        x0, y0, h0 = in_list[i]

for Cx in range(0, 101):
    for Cy in range(0, 101):
        for xyh in in_list:
            x, y, h = xyh[0], xyh[1], xyh[2]
            H = h0 + abs(x0-Cx) + abs(y0-Cy)
            if h != max(H-abs(x-Cx)-abs(y-Cy), 0):
                break
        else:
            print(Cx, Cy, H)


