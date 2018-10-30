A, B, C = map(int, input().split())

if (A*B*C) % 2 == 0:
    print(0)
else:
    abc = [A, B, C]
    abc.sort()
    print(abc[0] * abc[1])
