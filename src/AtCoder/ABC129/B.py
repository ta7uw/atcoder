N = int(input())
w_list = list(map(int, input().split()))

ans = float("inf")
for t in range(1, N + 1):
    ans = min(ans, abs(sum(w_list[:t]) - sum(w_list[t:])))

print(ans)
