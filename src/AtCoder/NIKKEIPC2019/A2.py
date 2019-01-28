N, A, B = map(int, input().split())
check = [0 for _ in range(N)]

for i in range(A):
    check[i] += 1

for i in range(B):
    check[-(i + 1)] += 1

cnt = 0
for c in check:
    if c == 2:
        cnt += 1

print(min(A, B), cnt)
