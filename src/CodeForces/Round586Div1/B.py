N = int(input())

items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))
import math

a1 = int(math.sqrt((items[0][1] * items[0][2]) // items[1][2]))

ans = [a1]
for i in range(1, N):
    ans.append(items[0][i] // a1)

for a in ans:
    print(a, end=" ")
print()
