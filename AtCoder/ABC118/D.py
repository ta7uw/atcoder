N, M = map(int, input().split())
a_list = list(map(int, input().split()))

items = {
    1: 2, 2: 5, 3: 5, 4: 4, 5: 5, 6: 6, 7: 3, 8: 7, 9: 6
}

dp = [-float("inf")] * (N + 1)
b_list = []
for a in a_list:
    need = items[a]
    if need <= N:
        dp[need] = 1
        b_list.append(a)

M = len(b_list)
dp[0] = 0
for i in range(N + 1):
    for b in b_list:
        if i - items[b] >= 0:
            if dp[i - items[b]] != -float("inf"):
                dp[i] = max(dp[i], dp[i - items[b]] + 1)

b_list.sort(reverse=True)
ans = ""

for i in range(dp[N]):
    for b in b_list:
        if dp[N - items[b]] == dp[N] - 1:
            ans += str(b)
            N -= items[b]
            break
print(ans)
