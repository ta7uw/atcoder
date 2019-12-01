N = int(input())
rain_list = [input().split("-") for i in range(N)]
rain_list = list(map(lambda x: [int(x[0]) // 5 * 5, -int(x[1]) // 5 * (-5)], rain_list))

for e in rain_list:
    if e[1] % 100 == 60:
        e[1] += 40

rain_list.sort()
result = []

for rain in rain_list:
    s, e = rain
    if len(result) == 0:
        result.append([s, e])
    else:
        last_rain = result[-1]
        ls, le = last_rain
        if s <= le <= e:
            result[-1][1] = e
        elif le < s:
            result.append([s, e])

for r in result:
    print("{:04}-{:04}".format(r[0], r[1]))
