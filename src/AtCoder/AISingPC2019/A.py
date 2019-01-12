n = int(input())
h = int(input())
w = int(input())
ans = 1

if n - h >= 1:
    ans *= (n - h + 1)

if n - w >= 1:
    ans *= (n - w + 1)

print(ans)
