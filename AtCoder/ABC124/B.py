N = int(input())
h_list = list(map(int, input().split()))

cnt = 0
max_r = 0

for h in h_list:
    if max_r <= h:
        cnt += 1
    max_r = max(max_r, h)

print(cnt)
