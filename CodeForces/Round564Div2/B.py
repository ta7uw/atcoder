N = int(input())
tmp = N

ans = 0
for b in range(1, 1000):
    if b + b - 1 >= N:
        ans = b
        break

print(ans)
for i in range(1, ans + 1):
    print(1, i)
    tmp -= 1
    if tmp == 0:
        exit()
for j in range(2, ans + 1):
    print(j, ans)
    tmp -= 1
    if tmp == 0:
        exit()
