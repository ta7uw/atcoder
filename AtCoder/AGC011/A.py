N, C, K = map(int, input().split())
t_list = [int(input()) for i in range(N)]

t_list.sort()

count = 0
passenger = 0
time = 0

for t in t_list:
    if passenger == 0:
        passenger += 1
        count += 1
        time = t
    elif 1 <= passenger < C:
        if t - time <= K:
            passenger += 1
        else:
            passenger = 1
            count += 1
            time = t
    else:
        passenger = 1
        count += 1
        time = t

print(count)
