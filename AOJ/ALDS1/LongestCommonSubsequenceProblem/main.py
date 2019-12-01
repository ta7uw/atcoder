def lcs(X, Y):
    m = len(X)
    n = len(Y)
    maxl = 0
    c = [[0 for j in range(n+1)] for i in range(m+1)]
    for i in range(1, m+1):
        for j in range(1, n+1):
            if X[i-1] == Y[j-1]:
                c[i][j] = c[i-1][j-1] + 1
            else:
                c[i][j] = max(c[i-1][j], c[i][j-1])
    return c[m][n]

n = int(input())
x_list = []
y_list = []

for i in range(n):
    x_list.append(input())
    y_list.append(input())

for i in range(n):
    print(lcs(x_list[i], y_list[i]))

