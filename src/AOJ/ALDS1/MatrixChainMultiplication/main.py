def matrix_chain_multiplication(n, m, p):
    for l in range(2, n+1):
        for i in range(1, n-l+2):
            j = i + l - 1
            m[i][j] = float("inf")
            for k in range(i, j):
                m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j])
    return m


n = int(input())
N = 100
p = [0 for i in range(N+1)]
m = [[0 for a in range(N+1)] for b in range(N+1)]

for i in range(1, n+1):
    p[i-1], p[i] = map(int, input().split())
print(matrix_chain_multiplication(n, m, p)[1][n])

