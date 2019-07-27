A, B = map(int, input().split())

if (B - A) % 2 == 0:
    print(A + (B-A)//2)
else:
    print("IMPOSSIBLE")

