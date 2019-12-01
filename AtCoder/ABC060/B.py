A, B, C = map(int, input().split())
for i in range(A, A*B, A):
    if i % B == C:
        print("YES")
        exit()
print("NO")
