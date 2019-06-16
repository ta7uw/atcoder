W, H, x, y = map(int, input().split())

print((H * W) / 2, end=" ")

if W / 2 == x and H / 2 == y:
    print(1)
else:
    print(0)
