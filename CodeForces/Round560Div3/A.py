N, X, Y = map(int, input().split())
S = input()

ans = 0
for i in range(N - X, N):
    s = S[i]
    if i == N - Y - 1 and s == "0":
        ans += 1
    elif i != N - Y - 1 and s == "1":
        ans += 1
print(ans)
