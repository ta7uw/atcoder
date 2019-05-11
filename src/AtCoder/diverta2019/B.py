R, G, B, N = map(int, input().split())

cnt = 0
for r in range(N + 1):
    for g in range(N + 1):
        b = N - (r * R + g * G)
        if b >= 0 and b % B == 0:
            cnt += 1
print(cnt)
