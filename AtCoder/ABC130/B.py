N, X = map(int, input().split())
l_list = list(map(int, input().split()))

ans = 0
z = 0
pr = 0
for i in range(N + 1):
    if i >= 1:
        z = l_list[i - 1] + pr
    if z <= X:
        ans += 1
    pr = z
print(ans)
