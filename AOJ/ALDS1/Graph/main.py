n = int(input())
in_list = []
for i in range(n):
    in_list.append(list(map(int, input().split())))

matrices = [["0" for _ in range(n)] for _ in range(n)]

for i in range(n):
    inp = in_list[i]
    u = inp[0]
    k = inp[1]
    for j in range(k):
        m = inp[j+2]
        matrices[i][m-1] = "1"

for i in range(n):
    print(" ".join(matrices[i]))