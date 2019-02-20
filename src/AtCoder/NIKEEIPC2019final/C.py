from collections import defaultdict

H, W, K = map(int, input().split())
rc = []
for i in range(K):
    rc.append(tuple(map(int, input().split())))

r_dict = defaultdict(int)
c_dict = defaultdict(int)

for i in range(H):
    r_dict[i] = W
for i in range(W):
    c_dict[i] = H

for r, c in rc:
    r_dict[r - 1] -= 1
    c_dict[c - 1] -= 1
total_r = H * W - K
total_c = H * W - K
if total_r % 2 == 0:
    mid_r = total_r // 2
else:
    mid_r = total_r // 2 + 1

if total_c % 2 == 0:
    mid_c = total_c // 2
else:
    mid_c = total_c // 2 + 1

r_cnt = 0
for i in range(H):
    r_cnt += r_dict[i]
    if r_cnt >= mid_r:
        r_i = i
        break

c_cnt = 0
for i in range(W):
    c_cnt += c_dict[i]
    if c_cnt >= mid_c:
        c_i = i
        break

ans = 0
for i in range(H):
    r = r_dict[i]
    ans += (abs(r_i - i) * r)

for i in range(W):
    c = c_dict[i]
    ans += (abs(c_i - i) * c)

print(ans)
