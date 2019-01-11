H, W = map(int, input().split())
grid = [list("#" + input() + "#") for _ in range(H)]

line = ["#" for _ in range(W + 2)]
grid.insert(0, line)
grid.append(line)
is_possible = True

before_grid = [["-" for _ in range(W + 2)] for _ in range(H + 2)]

for i in range(1, H + 1):
    for j in range(1, W + 1):
        if grid[i][j] == ".":
            before_grid[i][j] = "."
            before_grid[i + 1][j] = "."
            before_grid[i + 1][j + 1] = "."
            before_grid[i][j + 1] = "."
            before_grid[i - 1][j + 1] = "."
            before_grid[i - 1][j] = "."
            before_grid[i - 1][j - 1] = "."
            before_grid[i][j - 1] = "."
            before_grid[i + 1][j - 1] = "."
for i in range(1, H + 1):
    for j in range(1, W + 1):
        if before_grid[i][j] != ".":
            before_grid[i][j] = "#"
change_lsit = []
for i in range(1, H + 1):
    for j in range(1, W + 1):
        if before_grid[i][j] == "#" or \
                before_grid[i + 1][j] == "#" or \
                before_grid[i + 1][j + 1] == "#" or \
                before_grid[i][j + 1] == "#" or \
                before_grid[i - 1][j + 1] == "#" or \
                before_grid[i - 1][j] == "#" or \
                before_grid[i - 1][j - 1] == "#" or \
                before_grid[i][j - 1] == "#" or \
                before_grid[i + 1][j - 1] == "#":
            change_lsit.append([i, j])
import copy
change_grid = copy.deepcopy(before_grid)
for change in change_lsit:
    change_grid[change[0]][change[1]] = "#"

for i in range(1, H + 1):
    for j in range(1, W + 1):
        if change_grid[i][j] != grid[i][j]:
            is_possible = False

if is_possible:
    print("possible")
    for i in range(1, H + 1):
        print("".join(before_grid[i][1:-1]))
else:
    print("impossible")