N = int(input())
items = []
for i in range(N):
    x, u = input().split()
    items.append((float(x), u))
bp = 380000.0

ans = 0

for x, u in items:
    if u == "JPY":
        ans += x
    else:
        ans += bp * x
print(ans)
