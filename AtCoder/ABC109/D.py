H, W = map(int, input().split())
N = 0
a_map = []
for i in range(H):
    a = list(map(int, input().split()))
    a_map.append(a)
result = []
for i in range(H):
    for j in range(W):
        if a_map[i][j]%2==1:
            if j < W - 1:
                N += 1
                result.append([i + 1, j + 1, i + 1, j + 2])
                a_map[i][j + 1] += 1;
                a_map[i][j] -= 1;
            elif i < H - 1:
                N += 1;
                result.append([i + 1, j + 1, i + 2, j + 1])
                a_map[i][j] -= 1;
                a_map[i + 1][j] += 1;
print(N)
for a in result:
    print(a[0], a[1], a[2], a[3])
