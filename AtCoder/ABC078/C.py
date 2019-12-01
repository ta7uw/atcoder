N, M = map(int, input().split())
times = 1900 * M + (N-M) * 100
print(times*(2**M))
