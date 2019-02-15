N, M = map(int, input().split())
p_list = [int(input()) for _ in range(N - 1)]
p_list = [-1] + p_list
bc = []
for _ in range(M):
    bc.append(tuple(map(int, input().split())))

bc = sorted(bc, key=lambda x: x[1])
pd = [0 for _ in range(N + 1)]
ans = 0
for b, c in bc:
    while True:
        pd[b] = c
        if pd[p_list[b]] == 0 and p_list[b] != 0:
            b = p_list[b]
        else:
            ans += c - pd[p_list[b]]
            break
print(ans)
