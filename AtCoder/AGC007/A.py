H, W = map(int, input().split())

result = []

for i in range(H):
    a = input()
    result.append(a)

possibility = True

for i in range(H):
    for j in range(W):
        if j != W - 1 and i != H - 1:
            if result[i][j] == "#" and result[i + 1][j] == result[i][j] and result[i][j + 1] == result[i][j]:
                possibility = False
        if i != 0 and j !=0:
            if result[i][j] == "#" and result[i-1][j] == "." and result[i][j-1] == ".":
                possibility = False
if possibility:
    print("Possible")
else:
    print("Impossible")
