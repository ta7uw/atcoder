N, K = map(int, input().split())

a_list = list(map(int, input().split()))
a_set = set(a_list)
if len(a_set) <= K:
    print(0)
else:
    a_map = {}
    for a in a_list:
        if a in a_map:
            a_map[a] += 1
        else:
            a_map[a] = 1
    margin = len(a_set) - K
    a_map = sorted(a_map.items(), key=lambda x:x[1])
    count = 0
    for i in range(margin):
        count += a_map[i][1]
    print(count)
