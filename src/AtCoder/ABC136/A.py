A, B, C = map(int, input().split())

if A >= B:
    print(max(0, C - (A - B)))
else:
    print(C)
