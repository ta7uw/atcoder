K, X = map(int, input().split())

start = max(-1000000, X - K + 1)
end = min(1000000, X + K - 1)

for i in range(X - K + 1, X + K):
    if start <= i <= end:
        print(i, end=" ")
