N = int(input())

ans = 0
for i in range(N, 0, -1):
    s = str(i)
    if len(s) % 2 == 1:
        ans += 1
print(ans)
