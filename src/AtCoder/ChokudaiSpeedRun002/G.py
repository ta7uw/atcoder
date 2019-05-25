N = int(input())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))
import fractions

for a, b in items:
    print(fractions.gcd(a, b))
