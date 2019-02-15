import math

R, C = map(int, input().split())

ans = 0
for i in range(1, R):
    for j in range(1, R):
        if i % C == 0 and j % C == 0:
            tmp = math.sqrt(i ** 2 + j ** 2)
            if tmp <= R:
                ans += 1
print(ans * 4)
