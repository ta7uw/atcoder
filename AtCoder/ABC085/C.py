N, Y = map(int, input().split())
 
x = -1
y = -1
z = -1
 
for a in range(N+1):
    for b in range(N-a+1):
        c = N - a -b
        if 10000 * a + 5000 * b + 1000 * c == Y:
            x, y, z = a, b, c
            print("{} {} {}".format(x, y, z))
            exit()
print("{} {} {}".format(x, y, z))
