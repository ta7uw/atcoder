x, y = map(int, input().split())

ans = 0
if abs(y) > abs(x):
    if x < 0: 
        ans += 1
    if y < 0:
        ans += 1
    ans += (abs(y)-abs(x))
else:
    if x > 0:
        ans += 1
    if y > 0:
        ans += 1
    ans += (abs(x)-abs(y))
print(ans)
