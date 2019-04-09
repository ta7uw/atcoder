N, M = map(int, input().split())
A = []
B = []
for i in range(N):
    A.append(list(map(int, input().split())))
for i in range(N):
    B.append(list(map(int, input().split())))

C = []

for i in range(N):
    tmp = []
    for j in range(M):
        a = A[i][j]
        b = B[i][j]
        tmp.append(a ^ b)
    C.append(tmp)

for i in range(N - 1):
    for j in range(M - 1):
        if C[i][j] == 0:
            continue
        else:
            C[i][j] = 0
            C[i + 1][j] = 1 if C[i + 1][j] == 0 else 0
            C[i][j + 1] = 1 if C[i][j + 1] == 0 else 0
            C[i + 1][j + 1] = 1 if C[i + 1][j + 1] == 0 else 0

for i in range(N):
    for j in range(M):
        c = C[i][j]
        if c == 1:
            print("No")
            exit()

print("Yes")
