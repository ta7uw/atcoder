L, X = map(int, input().split())
if (X // L) % 2 == 0:
    print(X % L)
else:
    print(L - X % L)
