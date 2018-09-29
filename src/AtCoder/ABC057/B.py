N, M = map(int, input().split())

ab_list = []
cd_list = []

for i in range(N):
    ab = list(map(int, input().split()))
    ab_list.append(ab)

for i in range(M):
    cd = list(map(int, input().split()))
    cd_list.append(cd)

for a, b in ab_list:
    num = -1
    min_num = 10 ** 10 + 1
    count = 0
    for c, d in cd_list:
        count += 1
        distance = abs(a-c) + abs(b-d)
        if distance < min_num:
            min_num = distance
            num = count
    print(num)
