"""
C - Strawberry Cakes
https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_c

一行ずつみていく。イチゴが存在しない行はスキップ。
存在する場合は最初のイチゴをみつけるまでに注意しながら、次のイチゴがみつかるまで同じピースになるようにわけていく。
最後にスキップされた行を上下でスキップされていない行をみつけ、その結果をコピーしてくる
"""
H, W, K = map(int, input().split())
grid = []
for i in range(H):
    grid.append(input())

cnt = 0
ans = [[-1 for _ in range(W)] for _ in range(H)]
for i in range(H):

    f = -1
    for j in range(W):
        if grid[i][j] == "#":
            f = j
    if f == -1:
        continue

    first = False
    for j in range(W):
        if grid[i][j] == "#":
            if not first:
                first = True
            cnt += 1
            ans[i][j] = cnt
        else:
            if not first:
                ans[i][j] = cnt + 1
            else:
                ans[i][j] = cnt

for i in range(H):
    if ans[i][0] == -1:
        for j in range(i, H):
            if ans[j][0] != -1:
                ans[i] = ans[j]
                break

        if ans[i][0] == -1:
            for j in range(i, -1, -1):
                if ans[j][0] != -1:
                    ans[i] = ans[j]
                    break


for i in range(H):
    for j in range(W):
        print(ans[i][j], end=" ")
    print()
