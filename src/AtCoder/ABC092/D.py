A, B = map(int, input().split())

grid = [["#" for _ in range(100)] for _ in range(100)]
for i in range(50, 100):
    for j in range(100):
        grid[i][j] = "."

a_count = 0
for i in range(49):
    for j in range(100):
        if a_count >= A - 1:
            continue
        if i % 2 == 1 and j % 2 == 1:
            grid[i][j] = "."
            a_count += 1

b_count = 0
for i in range(51, 100):
    for j in range(100):
        if b_count >= B - 1:
            continue
        if i % 2 == 1 and j % 2 == 1:
            grid[i][j] = "#"
            b_count += 1

print(100, 100)
for i in range(100):
    print("".join(grid[i]))
