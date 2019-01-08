N, A, B = map(int, input().split())
x_list = list(map(int, input().split()))

ans = 0

for i in range(1, N):
    ans += min(B, A * (x_list[i] - x_list[i - 1]))
print(ans)
