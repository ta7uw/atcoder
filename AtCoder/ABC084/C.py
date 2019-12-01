N = int(input())

trains = []
for i in range(1, N):
    trains.append(list(map(int, input().split())))

for i in range(1, N+1):
    if i == N:
        print(0)
        continue
    result_time = 0
    for j, train in enumerate(trains):
        if j + 1 < i:
            continue
        c, s, f = train
        if result_time < s:
            result_time = s
        else:
            while result_time % f != 0:
                result_time += 1
        result_time += c

    print(result_time)

