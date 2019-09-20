N = int(input())

grid = [["*"] * N for _ in range(N)]

grid[0][0] = "W"

for i in range(N):
    for j in range(N):
        if grid[i][j] == "*":
            if j == 0:
                if grid[i - 1][j] == "W":
                    grid[i][j] = "B"
                else:
                    grid[i][j] = "W"
            else:
                if grid[i][j - 1] == "W":
                    grid[i][j] = "B"
                else:
                    grid[i][j] = "W"
        if grid[i][j] == "W":
            if 0 <= i - 2 < N and 0 <= j + 1 < N:
                if grid[i - 2][j + 1] == "*":
                    grid[i - 2][j + 1] = "B"
            if 0 <= i - 1 < N and 0 <= j + 2 < N:
                if grid[i - 1][j + 2] == "*":
                    grid[i - 1][j + 2] = "B"
            if 0 <= i + 1 < N and 0 <= j + 2 < N:
                if grid[i + 1][j + 2] == "*":
                    grid[i + 1][j + 2] = "B"
            if 0 <= i + 2 < N and 0 <= j + 1 < N:
                if grid[i + 2][j + 1] == "*":
                    grid[i + 2][j + 1] = "B"
            if 0 <= i + 2 < N and 0 <= j - 1 < N:
                if grid[i + 2][j - 1] == "*":
                    grid[i + 2][j - 1] = "B"
            if 0 <= i + 1 < N and 0 <= j - 2 < N:
                if grid[i + 1][j - 2] == "*":
                    grid[i + 1][j - 2] = "B"
            if 0 <= i - 1 < N and 0 <= j + 2 < N:
                if grid[i - 1][j + 2] == "*":
                    grid[i - 1][j + 2] = "B"
            if 0 <= i - 2 < N and 0 <= j - 1 < N:
                if grid[i - 2][j - 1] == "*":
                    grid[i - 2][j - 1] = "B"
        else:
            if 0 <= i - 2 < N and 0 <= j + 1 < N:
                if grid[i - 2][j + 1] == "*":
                    grid[i - 2][j + 1] = "W"
            if 0 <= i - 1 < N and 0 <= j + 2 < N:
                if grid[i - 1][j + 2] == "*":
                    grid[i - 1][j + 2] = "W"
            if 0 <= i + 1 < N and 0 <= j + 2 < N:
                if grid[i + 1][j + 2] == "*":
                    grid[i + 1][j + 2] = "W"
            if 0 <= i + 2 < N and 0 <= j + 1 < N:
                if grid[i + 2][j + 1] == "*":
                    grid[i + 2][j + 1] = "W"
            if 0 <= i + 2 < N and 0 <= j - 1 < N:
                if grid[i + 2][j - 1] == "*":
                    grid[i + 2][j - 1] = "W"
            if 0 <= i + 1 < N and 0 <= j - 2 < N:
                if grid[i + 1][j - 2] == "*":
                    grid[i + 1][j - 2] = "W"
            if 0 <= i - 1 < N and 0 <= j + 2 < N:
                if grid[i - 1][j + 2] == "*":
                    grid[i - 1][j + 2] = "W"
            if 0 <= i - 2 < N and 0 <= j - 1 < N:
                if grid[i - 2][j - 1] == "*":
                    grid[i - 2][j - 1] = "W"
for i in range(N):
    for j in range(N):
        print(grid[i][j], end="")
    print()
