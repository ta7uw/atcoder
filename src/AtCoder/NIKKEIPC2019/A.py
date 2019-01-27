N, A, B = map(int, input().split())
print(min(A, B), end=" ")
if N - A <= B:
    print(B - N + A)
else:
    print(0)
