H, W = map(int, input().split())
input_list = []
for i in range(H):
    input_list.append(input())
def contain_sharp(x, y):
    if input_list[y][x] == ".": return True
    dxy = [[0,1], [0, -1], [1,0],[-1,0]]
    for dx,dy in dxy:
        if 0<= y + dy < H and 0 <= x + dx < W:
            if input_list[y+dy][x+dx] == "#":
                return True
    else :
        return False


for y in range(H):
    for x in range(W):
        if not contain_sharp(x,y):
            print("No")
            exit()
print("Yes")
            
