D, G = map(int, input().split())

score_map = {}
for i in range(D):
    score_map[i] = list(map(int, input().split()))

result_list = []
for bit in range(1 << D):
    sum = 0
    result = 0
    not_used = D
    for i in range(D):
        if 1 & bit >> i:
            sum += score_map[i][1] + 100 * (i + 1) * score_map[i][0]
            result += score_map[i][0]
        else:
            not_used = i

    if not_used != D:
        for p in range(score_map[not_used][0]):
            if sum + (not_used + 1) * 100 * p >= G:
                result_list.append(result + p)

    else:
        if sum >= G:
            result_list.append(result)

print(min(result_list))
