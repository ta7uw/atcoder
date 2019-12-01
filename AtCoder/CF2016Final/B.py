N = int(input())

for i in range(1, N + 1):
    tmp = i * (i + 1) // 2
    if tmp >= N:
        margin = tmp - N
        for j in range(1, i + 1):
            if margin == j:
                continue
            print(j)
        exit()
