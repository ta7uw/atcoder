N, C = map(int, input().split())
time = 10**5+1
channel_list = [[0 for _ in range(time)]for _ in range(C)]
count_list = [0 for _ in range(time)]
for i in range(N):
    s, t, c = map(int, input().split())
    channel_list[c-1][s-1] += 1
    channel_list[c-1][t] -= 1

for i in range(C):
    for t in range(1, time):
        channel_list[i][t] += channel_list[i][t-1]
        if channel_list[i][t] >= 1:
            count_list[t] += 1
print(max(count_list))
