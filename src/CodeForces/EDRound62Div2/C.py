import heapq

N, K = map(int, input().split())
items = []
for i in range(N):
    items.append(tuple(map(int, input().split())))

b_index = sorted([(i, items[i][1]) for i in range(N)], key=lambda x: -x[1])

ans = -1
sum_num = 0
que = []
heapq.heapify(que)

for i, b in b_index:
    t = items[i][0]
    if len(que) < K:
        heapq.heappush(que, t)
        sum_num += t
    else:
        rem = heapq.heappop(que)
        if rem < t:
            heapq.heappush(que, t)
            sum_num -= rem
            sum_num += t
        else:
            heapq.heappush(que, rem)
    ans = max(ans, b * sum_num)
print(ans)
