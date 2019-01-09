def lcs(x, y):
    m = len(x)
    n = len(y)

    c = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if x[i - 1] == y[j - 1]:
                c[i][j] = c[i - 1][j - 1] + 1
            else:
                c[i][j] = max(c[i - 1][j], c[i][j - 1])

    lcs_str = ''
    i, j = m, n
    while i > 0 and j > 0:
        if x[i-1] == y[j-1]:
            lcs_str += x[i-1]
            i -= 1
            j -= 1
        else:
            if c[i][j] == c[i-1][j]:
                i -= 1
            else:
                j -= 1

    return lcs_str[::-1]


s = input()
t = input()
print(lcs(s, t))
