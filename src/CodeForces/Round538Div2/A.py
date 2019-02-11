x, y, z = map(int, input().split())
a, b, c = map(int, input().split())

if a < x:
    print("NO")
    exit()

a -= x

if a + b < y:
    print("NO")
    exit()

grape = a + b - y

if grape + c < z:
    print("NO")
    exit()

print("YES")
