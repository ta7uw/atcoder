N, K = map(int, input().split())
a_list = list(map(int, input().split()))

dp = [False] * (K + 1)

for i in range(1, K + 1):
    for a in a_list:
        if i - a < 0:
            continue
        if not dp[i - a]:
            dp[i] = True
            break

if dp[-1]:
    print("First")

else:
    print("Second")
