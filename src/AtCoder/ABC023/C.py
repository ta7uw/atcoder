R, C, K = map(int, input().split())
n = int(input())
r_list = [0 for _ in range(R)]
c_list = [0 for _ in range(C)]
points = []
for i in range(n):
    r, c = map(int, input().split())
    r_list[r-1] += 1
    c_list[c-1] += 1
    points.append((r-1, c-1))


r_count = [0 for _ in range(K+1)]
c_count = [0 for _ in range(K+1)]

for row in r_list:
    if row <= K:
        r_count[row] += 1
for col in c_list:
    if col <= K:
        c_count[col] += 1

count = 0

for i in range(K + 1):
    count += r_count[i] * c_count[K - i]
for i in range(n):
    r, c = points[i]

    if r_list[r] + c_list[c] == K:
        count -= 1
    elif r_list[r] + c_list[c] == K + 1:
        count += 1
print(count)
