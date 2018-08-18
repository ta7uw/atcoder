N, M, Q = map(int, input().split())
 
x = [[0 for i in range(N + 1)] for j in range(N + 1)]
 
for i in range(M):
    l, r = map(int, input().split())
    x[l][r] += 1
 
for i in range(1, N + 1):
    for j in range(1, N + 1):
        x[i][j] += x[i - 1][j] + x[i][j - 1] - x[i - 1][j - 1]
 
for i in range(Q):
    p, q = map(int, input().split())
 
    ans = x[N][q] - x[p - 1][q]
    print(ans)
