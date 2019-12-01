N, K = map(int, input().split())

# 1回 K
ans = (N - K) * (K - 1) * 6

# 2回 K
ans += (N - 1) * 3

# 3回 K
ans += 1

print(ans / pow(N, 3))
