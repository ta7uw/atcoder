N = int(input())
p_list = list(map(int, input().split()))

dp = [False for _ in range(100 * 100 + 1)]
dp[0] = True

for p in p_list:
    for i in range(100 * 99 + 1, -1, -1):
        if dp[i]:
            dp[i + p] = True

count = 0
for d in dp:
    if d:
        count += 1

print(count)
