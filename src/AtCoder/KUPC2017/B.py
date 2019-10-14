N, S, T = map(int, input().split())

ans = 0

while T > 0:
    if S == T:
        print(ans)
        exit()
    ans += 1
    T //= 2
print(-1)
