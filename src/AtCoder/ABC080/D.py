N, C = map(int, input().split())
channel_list = [[0 for _ in range(10**5+1)]for _ in range(C)]
count_list = [0 for _ in range(10**5+1)]
for i in range(N):
    s, t, c = map(int, input().split())
    channel_list[c-1][s-1] += 1
    channel_list[c-1][t] -= 1

for i in range(C):
    for t in range(1, 10**5):
        if t == 10 ** 5:
            continue
        channel_list[i][t] += channel_list[i][t-1]
        if channel_list[i][t] >= 1:
            count_list[t] += 1
x = 0
for t in range(1, 10**5+1):
    count = count_list[t]
    if count > x:
        x = count
print(x)
