N, M = map(int, input().split())
A = []
B = []
for i in range(N):
    A.append(list(map(int, input().split())))
for i in range(N):
    B.append(list(map(int, input().split())))

a_row = 0
b_row = 0

for i in range(N):
    a_row = sum(A[i])
    b_row = sum(B[i])
    if a_row % 2 == b_row % 2:
        a_row = 0
        b_row = 0
        continue
    else:
        print("No")
        exit()

a_column = 0
b_column = 0

for j in range(M):
    for i in range(N):
        a_column += A[i][j]
        b_column += B[i][j]

    if a_column % 2 == b_column % 2:
        a_column = 0
        b_column = 0
        continue
    else:
        print("No")
        exit()
print("Yes")
