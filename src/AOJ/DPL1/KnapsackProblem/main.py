n, w = map(int, input().split())
items = []

for i in range(n):
    items.append(list(map(int, input().split())))


def knapsack(n, w, items):
    c = [[0 for i in range(w + 1)] for j in range(n + 1)]
    g = [[0 for i in range(w + 1)] for j in range(n + 1)]

    for i in range(w + 1):
        c[0][i] = 0
        g[0][i] = 1

    for i in range(n + 1):
        c[i][0] = 0

    for i in range(1, n + 1):
        for j in range(1, w + 1):
            c[i][j] = c[i - 1][j]
            g[i][j] = 0
            item = items[i - 1]
            if item[1] > j:
                continue
            if item[0] + c[i - 1][j - item[1]] > c[i - 1][j]:
                c[i][j] = item[0] + c[i - 1][j - item[1]]
                g[i][j] = 1

    max_value = c[n][w]
    routes = []
    for i in range(n, 0, -1):
        if g[i][w] == 1:
            routes.append(i)
            w -= items[i - 1][1]

    return max_value, routes


result, _ = knapsack(n, w, items)
print(result)
