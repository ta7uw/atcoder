N, M = map(int, input().split())
s_list = []
for i in range(N):
    s_list.append(input())
def check_going(x, y):
    count = 0
    if s_list[y][x] == "#": return count
    dxy = [[1,0], [-1, 0], [0, -1], [0, 1]]
    turn_right = [[0, -1], [0, 1], [-1,0], [1,0]]
    for xy, r in zip(dxy, turn_right):
        dx, dy = xy
        rx, ry = r
        go_ahead = True
        j = 1
        while(go_ahead):    
            if 0 <= x + j*dx < M and 0 <= y +j* dy < N:
                go_point =s_list[y +j* dy][x +j* dx ]
                if go_point == "#":
                    go_ahead = False
                    continue
                not_clash = True
                m = 1
                while(not_clash):
                    if 0 <= x + j*dx +m* rx < M and 0 <= y +j* dy + m*ry < N:
                        turned_point = s_list[y +j* dy +m* ry][x +j* dx+m*rx]
                        if turned_point == "#":
                            not_clash = False
                        else:
                            m += 1
                            count +=1
                    else:
                        not_clash = False
                j += 1
            else :
                go_ahead = False
    return count
total = 0
for n in range(N):
    for m in range(M):
        total += check_going(m, n)
print(total)


