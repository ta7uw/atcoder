N = int(input())
A = input()
B = input()
C = input()
ans = 0
for i in range(N):
    a = A[i]
    b = B[i]
    c = C[i]

    if a == b == c:
        continue
    elif a == b:
        ans += 1

    elif a == c:
        ans += 1
    elif c == b:
        ans += 1
    else:
        ans += 2

print(ans)
