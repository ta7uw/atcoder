N = int(input())
line = []
for i in range(N):
    line.append(list(map(int, input().split())))

count = 0
for j in line:
    count += j[1] - j[0] + 1
print(count)

