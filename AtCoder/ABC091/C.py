n = int(input())
red = []
for i in range(n):
    a, b = map(int, input().split())
    red.append((a, b))

blue = []
for i in range(n):
    c, d = map(int, input().split())
    blue.append((c, d))

red = sorted(red, key=lambda x: x[1])
blue.sort()

count = 0
while len(blue) >= 1:
    c, d = blue.pop(0)
    tmp = []
    r = []
    while len(red) >= 1:
        a, b = red.pop()
        if a < c and b < d:
            r.append((a, b))
        else:
            tmp.append((a, b))
    if len(r) >= 1:
        count += 1
        r = sorted(r, key=lambda x:x[1])
        r.pop()
        tmp.extend(r)
    red.extend(tmp)
print(count)
