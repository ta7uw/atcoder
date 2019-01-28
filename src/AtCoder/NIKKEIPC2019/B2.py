N = int(input())
A, B, C = input(), input(), input()

ans = 0
for i in range(N):
    abc = A[i], B[i], C[i]
    ans += len(set(abc)) - 1
print(ans)
