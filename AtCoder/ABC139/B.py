A, B = map(int, input().split())
if B == 1:
    print(0)
    exit()
ans = 0
for i in range(1, 1000):
    tmp = A + (A - 1) * (i - 1)
    if tmp >= B:
        print(i)
        break
