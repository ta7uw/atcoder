N, L = map(int, input().split())

ans = 0
margin = float("inf")
for i in range(1, N + 1):

    tar = 0
    for j in range(1, N + 1):
        tar += L + j - 1

    res = 0
    for j in range(1, N + 1):
        if j == i:
            continue
        else:
            res += L + j - 1

    if abs(tar - res) < margin:
        ans = res
        margin = abs(tar - res)

print(ans)
